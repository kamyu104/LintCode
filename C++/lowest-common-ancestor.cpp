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
public:
    /**
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        return LCAHelper(root, A, B).second;
    }
    
    // Returns a pair of int and node pointer; int field is 0, 1, or 2 depending
    // on how many of node0 and node1 are present in tree. If both are present in
    // tree, the node pointer is a common ancestor. It may not be the LCA
    // initially, but it will be LCA when the algorithm terminates.
    pair<int, TreeNode*> LCAHelper(TreeNode *tree, TreeNode *A, TreeNode *B) {
        if (tree == nullptr) {
            return {0, nullptr};
        }
        
        auto left_result = LCAHelper(tree->left, A, B);
        if (left_result.first == 2) {  // Found both nodes in the left subtree.
            return left_result;
        }
        
        auto right_result = LCAHelper(tree->right, A, B);
        if (right_result.first == 2) {  // Found both nodes in the right subtree.
            return right_result;
        }
        
        int num_target_nodes = left_result.first + right_result.first +
                               (tree == A) + (tree == B);
        
        return {num_target_nodes, num_target_nodes == 2 ? tree : nullptr};
    }
};
