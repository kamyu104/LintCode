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
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
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
                    node->right = curr;
                    curr = curr->left;
                } else {
                    res.emplace_back(curr->val);
                    prev = curr;
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
class Solution2 {
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> res;
        TreeNode *cur = root;
        while (!s.empty() || cur) {
            if (cur) {
                s.emplace(cur);
                cur = cur->left;
            } else {
                cur = s.top();
                s.pop();
                res.emplace_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
};
