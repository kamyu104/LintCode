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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &in, vector<int> &post) {
        unordered_map<int, size_t> in_entry_idx_map;
        for (size_t i = 0; i < in.size(); ++i) {
            in_entry_idx_map.emplace(in[i], i);
        }
        return ReconstructPostInOrdersHelper(post, 0, post.size(), in, 0, in.size(),
                                             in_entry_idx_map);
    }

    TreeNode * ReconstructPostInOrdersHelper(const vector<int>& post, size_t post_s, size_t post_e,
                                             const vector<int>& in, size_t in_s, size_t in_e,
                                             const unordered_map<int, size_t>& in_entry_idx_map) {
        if (post_e > post_s && in_e > in_s) {
            auto idx = in_entry_idx_map.at(post[post_e - 1]);
            auto left_tree_size = idx - in_s;

            TreeNode *node = new TreeNode(post[post_e - 1]);
            // Recursively builds the left subtree.
            node->left =ReconstructPostInOrdersHelper(post, post_s, post_s + left_tree_size,
                                                      in, in_s, idx, in_entry_idx_map);
            // Recursively builds the right subtree.
            node->right = ReconstructPostInOrdersHelper(post, post_s + left_tree_size, post_e - 1,
                                                        in, idx + 1, in_e, in_entry_idx_map);
            return node;
        }
        return nullptr;
    }
};
