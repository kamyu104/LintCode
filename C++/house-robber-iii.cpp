// Time:  O(n)
// Space: O(h)

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber3(TreeNode* root) {
        const auto& res = houseRobber3Helper(root);
        return max(res.first, res.second);
    }

private:
    pair<int, int> houseRobber3Helper(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }
        const auto& left = houseRobber3Helper(root->left);
        const auto& right = houseRobber3Helper(root->right);
        return {root->val + left.second + right.second,
                max(left.first, left.second) + max(right.first, right.second)};
    }
};
