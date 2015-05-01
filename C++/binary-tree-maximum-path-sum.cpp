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
     * @return: An integer
     */
    int maxPathSum(TreeNode *root) {
        maxPathSumRecu(root);
        return max_sum_;
    }
    
    // Return max height and update max path sum for each node.
    int maxPathSumRecu(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        
        // Get max descendant sum of children.
        // If the sum is less than zero, it can't be the path with max sum.
        int left = max(0, maxPathSumRecu(root->left));
        int right = max(0, maxPathSumRecu(root->right));
        
        // "max path sum" equals to:
        // "max left descendant sum" -> root -> "max right descendant sum".
        max_sum_ = max(max_sum_, root->val + left + right);
        
        // Return max descendant sum.
        return root->val + max(left, right);
    }
private:
    int max_sum_ = INT_MIN;
};
