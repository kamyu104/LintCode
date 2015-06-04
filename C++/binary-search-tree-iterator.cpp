// Time:  O(1), amortized
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
 * Example of iterate a tree:
 * Solution iterator = Solution(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
class Solution {
public:
    //@param root: The root of binary tree.
    Solution(TreeNode *root) {
        curr = root;
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        return !s.empty() || curr != nullptr;
    }

    //@return: return next node
    TreeNode* next() {
        // Go to left most descendant.
        while (curr != nullptr) {
            s.emplace(curr);
            curr = curr->left;
        }
        curr = s.top(); // Left most node.
        s.pop();

        TreeNode *node = curr;
        curr = curr->right; // Visit right child.

        return node;
    }
private:
    stack<TreeNode *> s;
    TreeNode *curr;
};

