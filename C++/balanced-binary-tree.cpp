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
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        return isBalancedRecu(root).first;
    }

    pair<bool, int> isBalancedRecu(TreeNode *root) {
        if (root == nullptr) {
            return {true, 0};
        }

        pair<bool, int> left = isBalancedRecu(root->left);
        pair<bool, int> right =  isBalancedRecu(root->right);

        if (left.first && right.first && abs(left.second - right.second) <= 1) {
            return {true, max(left.second, right.second) + 1};
        }
        else {
            return {false, 0};
        }
    }
};
