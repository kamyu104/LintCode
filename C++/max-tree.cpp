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
 public:
    /**
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    TreeNode* maxTree(vector<int> A) {
        vector<TreeNode *> nodeStack;
        for (int i = 0; i < A.size(); ++i) {
            auto node = new TreeNode(A[i]);
            while (!nodeStack.empty() && A[i] > nodeStack.back()->val) {
                node->left = nodeStack.back();
                nodeStack.pop_back();
            }
            if (!nodeStack.empty()) {
                nodeStack.back()->right = node;
            }
            nodeStack.emplace_back(node);
        }
        return nodeStack.front();
    }
};
