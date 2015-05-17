// Time:  O(h)
// Space: O(1)

class Solution {
public:
    /**
     * @param root: The root of the binary search tree->
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree->
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        if (root == nullptr) {
            return node;
        }
        TreeNode* curr = root;
        while (true) {
            if (node->val < curr->val) {
                if (curr->left != nullptr) {
                    curr = curr->left;
                }
                else {
                    curr->left = node;
                    break;
                }
            } else if (node->val > curr->val) {
                if (curr->right != nullptr) {
                    curr = curr->right;
                }
                else {
                    curr->right = node;
                    break;
                }
            } else {
                curr->val = node->val;
                break;
            }
        }
        return root;
    }
};

class Solution2 {
public:
    /**
     * @param root: The root of the binary search tree->
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree->
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        if (root == nullptr) {
            return node;
        }
        if (node->val < root->val) {
            root->left = insertNode(root->left, node);
        }
        else if (node->val > root->val) {
            root->right = insertNode(root->right, node);
        }
        else {
            root->val = node->val;
        }
        return root;
    }
};
