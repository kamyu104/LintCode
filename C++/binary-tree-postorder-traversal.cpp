// Time:  O(n)
// Space: O(1)

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
// Morris Traversal.
class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        TreeNode dummy(INT_MIN);
        dummy.left = root;
        TreeNode *curr = &dummy;
        while (curr) {
            if (!curr->left) {
                curr = curr->right;
            } else {
                TreeNode *node = curr->left;
                while (node->right && node->right != curr) {
                    node = node->right;
                }
                if (!node->right) {
                    node->right = curr;
                    curr = curr->left;
                } else {
                    vector<int> v = trace_back(curr->left, node);
                    res.insert(res.end(), v.begin(), v.end());
                    node->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        return res;
    }

    vector<int> trace_back(TreeNode *frm, TreeNode *to) {
        vector<int> res;
        TreeNode *curr = frm;
        while (curr != to) {
            res.emplace_back(curr->val);
            curr = curr->right;
        }
        res.emplace_back(to->val);
        reverse(res.begin(), res.end());
        return res;
    }
};

// Time:  O(n)
// Space: O(h)
// Stack solution.
class Solution2 {
    /**
     * @param root: The root of binary tree.
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        if (root == nullptr) {  // Empty tree.
            return {};
        }

        stack<TreeNode *> path_stack;
        TreeNode * prev = nullptr;
        path_stack.emplace(root);
        vector<int> postorder_sequence;

        while (!path_stack.empty()) {
            auto curr = path_stack.top();
            if (prev == nullptr || prev->left == curr ||
                prev->right == curr) {
                // We came down to curr from prev.
                if (curr->left != nullptr) {  // Traverse left.
                    path_stack.emplace(curr->left);
                } else if (curr->right != nullptr) {  // Traverse right.
                    path_stack.emplace(curr->right);
                } else {  // Leaf node, so visit current node.
                    postorder_sequence.emplace_back(curr->val);
                    path_stack.pop();
                }
            } else if (curr->left == prev) {
                // Done with left, so now traverse right.
                if (curr->right != nullptr) {
                    path_stack.emplace(curr->right);
                } else {  // No right child, so visit curr.
                    postorder_sequence.emplace_back(curr->val);
                    path_stack.pop();
                }
            } else {
                // Finished traversing left and right, so visit curr.
                postorder_sequence.emplace_back(curr->val);
                path_stack.pop();
            }
            prev = curr;
        }
        return postorder_sequence;
    }
};
