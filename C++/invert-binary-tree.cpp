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

// Time:  O(n)
// Space: O(w), w is the max number of nodes of the levels.
// BFS solution.
class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
        if (root != nullptr) {
            queue<TreeNode*> nodes;
            nodes.emplace(root);
            while (!nodes.empty()) {
                auto node = nodes.front();
                nodes.pop();
                swap(node->left, node->right);
                if (node->left != nullptr) {
                    nodes.emplace(node->left);
                }
                if (node->right != nullptr) {
                    nodes.emplace(node->right);
                }
            }
        }
    }
};

// Time:  O(n)
// Space: O(h)
// Stack solution.
class Solution2 {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
        if (root != nullptr) {
            stack<TreeNode*> nodes;
            nodes.emplace(root);
            while (!nodes.empty()) {
                auto node = nodes.top();
                nodes.pop();
                swap(node->left, node->right);
                if (node->left != nullptr) {
                    nodes.emplace(node->left);
                }
                if (node->right != nullptr) {
                    nodes.emplace(node->right);
                }
            }
        }
    }
};

// Time:  O(n)
// Space: O(h) 
// DFS, Recursive solution.
class Solution3 {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
        if (root != nullptr) {
            swap(root->left, root->right);
            invertBinaryTree(root->left);
            invertBinaryTree(root->right);
        }
    }
};
