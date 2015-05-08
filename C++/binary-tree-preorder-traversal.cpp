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
