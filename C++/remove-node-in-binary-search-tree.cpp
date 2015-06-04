// Time:  O(h)
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
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) {
        if (root == nullptr) {
            return nullptr;
        }
        if (value < root->val) {
            root->left = removeNode(root->left, value);
        }
        else if (value > root->val) {
            root->right = removeNode(root->right, value);
        }
        else {  // Find the target node.
            if (root->left == nullptr) {
                return root->right;
            } else if (root->right == nullptr) {
                return root->left;
            }
            TreeNode *node = root;
            root = findMin(node->right);
            root->right = deleteMin(node->right);
            root->left = node->left;
        }
        return root;
    }

    // Find the min node of the binary search tree.
    TreeNode* findMin(TreeNode* node) {
        while (node != nullptr && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Delete the min node of the binary search tree.
    TreeNode* deleteMin(TreeNode* node) {
        // No left child.
        if (node->left == nullptr) {
            return node->right;
        }

        TreeNode *root = node;

        // Find the parent of the min.
        TreeNode* parent;
        while (node != nullptr && node->left != nullptr) {
            parent = node;
            node = node->left;
        }

        // Cut the parent relationship to the min,
        // and take the right child of the min.
        parent->left = node->right;

        return root;
    }
};
