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
     * @param root the root of binary tree
     * @param target an integer
     * @return all valid paths
     */
    vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        binaryTreePathHelper(root, target, &cur, &res);
        return res;
    }
    
    void binaryTreePathHelper(const TreeNode *root, const int target,
                              vector<int> *cur,  vector<vector<int>> *res) {
        if (!root) {
            return;
        }

        cur->emplace_back(root->val);
        if (!root->left && !root->right && root->val == target) {
            res->emplace_back(*cur);
        } else {
            binaryTreePathHelper(root->left, target - root->val, cur, res);
            binaryTreePathHelper(root->right, target - root->val, cur, res);
        }
        cur->pop_back();
    }
};
