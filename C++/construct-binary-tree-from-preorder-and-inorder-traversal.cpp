// Time:  O(n)
// Space: O(h)

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
    /**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &pre, vector<int> &in) {
        unordered_map<int, size_t> in_entry_idx_map;
        for (size_t i = 0; i < in.size(); ++i) {
            in_entry_idx_map.emplace(in[i], i);
        }
        return ReconstructPreInOrdersHelper(pre, 0, pre.size(), in, 0, in.size(),
                                            in_entry_idx_map);
    }

    // Reconstructs the binary tree from pre[pre_s : pre_e - 1] and
    // in[in_s : in_e - 1].
    TreeNode *ReconstructPreInOrdersHelper(const vector<int>& pre, size_t pre_s, size_t pre_e,
                                           const vector<int>& in, size_t in_s, size_t in_e,
                                           const unordered_map<int, size_t>& in_entry_idx_map) {
        if (pre_e > pre_s && in_e > in_s) {
            auto idx = in_entry_idx_map.at(pre[pre_s]);
            auto left_tree_size = idx - in_s;

            TreeNode *node = new TreeNode(pre[pre_s]);
            // Recursively builds the left subtree.
            node->left = ReconstructPreInOrdersHelper(pre, pre_s + 1, pre_s + 1 + left_tree_size,
                                                      in, in_s, idx, in_entry_idx_map);
            // Recursively builds the right subtree.
            node->right = ReconstructPreInOrdersHelper(pre, pre_s + 1 + left_tree_size, pre_e,
                                                       in, idx + 1, in_e, in_entry_idx_map);
            return node;
        }
        return nullptr;
    }
};
