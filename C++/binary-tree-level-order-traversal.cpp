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
        vector<vector<int>> output;
        queue<TreeNode *> que;
        vector<int> cur_level;
        
        // Enqueue when node is not nullptr.
        if (root) {
            que.emplace(root);
        }
        
        int cur_level_cnt = que.size();
        while (!que.empty()) {
            TreeNode *node = que.front();
            que.pop();
            --cur_level_cnt;
            
            cur_level.emplace_back(node->val);
            
            // Enqueue the next level.
            if (node->left) {
                que.emplace(node->left);
            }
            if (node->right) {
                que.emplace(node->right);
            }
            
            // Current level has been all visited.
            if (cur_level_cnt == 0) {
                cur_level_cnt = que.size();
                output.emplace_back(move(cur_level));
            }
        }
        return output;
    }
};

