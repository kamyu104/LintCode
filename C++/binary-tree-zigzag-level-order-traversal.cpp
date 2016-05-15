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

// Using stack.
class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: A list of lists of integer include
     *          the zigzag level order traversal of its nodes' values
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> result;
        stack<TreeNode *> current_level;

        if (root != nullptr) {
            current_level.emplace(root);
        }

        bool normal_order = true;
        while (!current_level.empty()) {
            vector<int> level;
            stack<TreeNode *> next_level;
            int size = current_level.size();
            while (!current_level.empty()) {
                auto *top = current_level.top();
                current_level.pop();
                level.emplace_back(top->val);
                if (normal_order) {
                    if (top->left != nullptr) {
                        next_level.emplace(top->left);
                    }
                    if (top->right != nullptr) {
                        next_level.emplace(top->right);
                    }
                } else {
                    if (top->right != nullptr) {
                        next_level.emplace(top->right);
                    }
                    if (top->left != nullptr) {
                        next_level.emplace(top->left);
                    }
                }
            }
            result.emplace_back(move(level));
            normal_order = !normal_order;
            swap(current_level, next_level);
        }

        return result;
    }
};

// Useing queue.
class Solution2 {
    /**
     * @param root: The root of binary tree.
     * @return: A list of lists of integer include
     *          the zigzag level order traversal of its nodes' values
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> result;
        queue<TreeNode *> que;

        if (root != nullptr) {
            que.emplace(root);
        }

        bool normal_order = true;
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
            if (!normal_order) {
                reverse(level.begin(), level.end());
            }
            result.emplace_back(move(level));
            normal_order = !normal_order;
        }

        return result;
    }
};
