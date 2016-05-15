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
        if (root == nullptr || root == A || root == B) {
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left, A, B);
        TreeNode *right = lowestCommonAncestor(root->right, A, B);
         // 1. If the current subtree contains both A and B,
         //    return their LCA.
         // 2. If only one of them is in that subtree,
         //    return that one of them.
         // 3. If neither of them is in that subtree,
         //    return the node of that subtree.
        return left ? (right ? root : left) : right;
    }
};
