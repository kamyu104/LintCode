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
     * @param root: The root of binary tree
     * @return root of new tree
     */
    TreeNode* cloneTree(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }

        auto clone_root = new TreeNode(root->val);
        clone_root->left = cloneTree(root->left);
        clone_root->right = cloneTree(root->right);
        
        return clone_root;
    }
};
