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

private:
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
        vector<int> res;
        stack<pair<TreeNode *, bool>> s;
        s.emplace(root, false);
        while (!s.empty()) {
            bool visited;
            tie(root, visited) = s.top();
            s.pop();
            if (root == nullptr) {
                continue;
            }
            if (visited) {
                res.emplace_back(root->val);
            } else {
                s.emplace(root, true);
                s.emplace(root->right, false);
                s.emplace(root->left, false);
            }
        }
        return res;
    }
};
