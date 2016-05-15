// Time:  O(n)
// Space: O(n)

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
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        queue<TreeNode *> que;

        if (root != nullptr) {
            que.emplace(root);
        }

        while (!que.empty()) {
            vector<int> level;
            int size = que.size();
            for (int i = 0; i < size; i++) {
                auto *front = que.front();
                que.pop();
                level.emplace_back(front->val);
                if (front->left != nullptr) {
                    que.emplace(front->left);
                }
                if (front->right != nullptr) {
                    que.emplace(front->right);
                }
            }
            result.emplace_back(move(level));
        }

        return result;
    }
};
