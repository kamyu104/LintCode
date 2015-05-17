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
     * @return: A list of lists of integer include
     *          the zigzag level order traversal of its nodes' values
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        bool isLeftToRight = true;
        vector<vector<int>> output;
        queue<TreeNode *> q;
        vector<int> cur_level;
        
        if (root == nullptr) {
            return output;
        }
        
        q.push(root);
        int cur_level_size = 1;
        while (!q.empty()) {
            // Get the front node in current level.
            TreeNode *n = q.front();
            q.pop();
            --cur_level_size;
            
            // Append to the current level.
            cur_level.emplace_back(n->val);
            
            if (n->left) {
                q.emplace(n->left);
            }
            if (n->right) {
                q.emplace(n->right);
            }
            
            // Current level comes to the end.
            // Goes to the next level.
            if (cur_level_size == 0) {
                if(!isLeftToRight) {
                    reverse(cur_level.begin(), cur_level.end());
                }
                isLeftToRight = !isLeftToRight;
                cur_level_size = q.size();
                output.emplace_back(move(cur_level));
            }
        }
        return output;
    }
};
