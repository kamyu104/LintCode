// Time:  O(n)
// Space: O(1)

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

// Morris Traversal.
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        TreeNode *prev = nullptr;
        TreeNode *curr = root;
        while (curr) {
            if (!curr->left) {
                res.emplace_back(curr->val);
                prev = curr;
                curr = curr->right;
            } else {
                TreeNode *node = curr->left;
                while (node->right && node->right != curr) {
                    node = node->right;
                }
                if (!node->right) {
                    res.emplace_back(curr->val);
                    prev = curr;
                    node->right = curr;
                    curr = curr->left;
                } else {
                    node->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        return res;
    }
};


// Time:  O(n)
// Space: O(h)
// Stack solution.
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        if (!root) {
            return {};
        }
        
        stack<TreeNode *> s;
        s.emplace(root);
        vector<int> res;
        while (!s.empty()) {
            auto curr = s.top();
            s.pop();
            res.emplace_back(curr->val);
            if (curr->right) {
                s.emplace(curr->right);
            }
            if (curr->left) {
                s.emplace(curr->left);
            }
        }
        return res;
    }
};
