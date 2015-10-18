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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode *root) {
        TreeNode *list_head = nullptr;
        flattenHelper(root, &list_head);
    }

    TreeNode *flattenHelper(TreeNode *root, TreeNode **list_head) {
        if (root) {
            flattenHelper(root->right, list_head);
            flattenHelper(root->left, list_head);
            root->right = *list_head;
            root->left = nullptr;
            *list_head = root;
        }
    }
};
