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
        if (A.empty()) {
            return NULL;
        }
        
        stack<TreeNode *> nodeStack;
        nodeStack.push(new TreeNode(A[0]));
        for (int i = 1; i < A.size(); ++i) {
            // The stack stores nodes in descending order.
            if (A[i] <= nodeStack.top()->val) {
                TreeNode *node = new TreeNode(A[i]);
                nodeStack.push(node);
            } else {
                // Pop every node which value is less than A[i],
                // and let them as right children of the last node less than A[i]
                TreeNode *smaller_node = nodeStack.top();
                nodeStack.pop();
                while (!nodeStack.empty() && nodeStack.top()->val < A[i]){
                    nodeStack.top()->right = smaller_node;
                    smaller_node = nodeStack.top();
                    nodeStack.pop();
                }
                
                // Pop the last node which value is less than A[i], and let it as right child,
                // and push A[i] to the stack.
                TreeNode *node = new TreeNode(A[i]);
                node->left = smaller_node;
                nodeStack.push(node);
            }
        }
        
        // Pop every node in the stack,
        // and let them as right children of the root
        TreeNode *root = nodeStack.top();
        nodeStack.pop();
        while (!nodeStack.empty()){
            nodeStack.top()->right = root;
            root = nodeStack.top();
            nodeStack.pop();
        }
        
        return root;
    }
};
