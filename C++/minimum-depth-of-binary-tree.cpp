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
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        // Both children exist.
        if (root->left != nullptr && root->right != nullptr) {
            return 1 + min(minDepth(root->left), minDepth(root->right));
        }
        else {
            return 1 + max(minDepth(root->left), minDepth(root->right));
        }
    }
};
