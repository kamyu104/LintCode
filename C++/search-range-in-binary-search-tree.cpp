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

// Recursive solution.
class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        vector<int> result;
        pair<int, int> interval{k1, k2};
        RangeLookupInBSTHelper(root, interval, &result);
        return result;
    }

    void RangeLookupInBSTHelper(const TreeNode* tree,
                                const pair<int, int>& interval,
                                vector<int>* result) {
        if (tree == nullptr) {
            return;
        }
        if (interval.first <= tree->val && tree->val <= interval.second) {
            // tree->data lies in the interval.
            RangeLookupInBSTHelper(tree->left, interval, result);
            result->emplace_back(tree->val);
            RangeLookupInBSTHelper(tree->right, interval, result);
        } else if (interval.first > tree->val) {
            RangeLookupInBSTHelper(tree->right, interval, result);
        } else {  // interval.second > tree->val
            RangeLookupInBSTHelper(tree->left, interval, result);
        }
    }
};

// Iterative solution.
class Solution2 {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        stack<TreeNode *> st;
        vector<int> output;

        pushLeft(st, root, k1);

        while (st.size() > 0) {
            TreeNode *t = st.top();
            st.pop();

            // Add valid nodes to the stack.
            if (t->val >= k1 && t->val <= k2) {
                output.emplace_back(t->val);
            }

            // Push until the min of right descendant.
            if (t->val <= k2)  {
                pushLeft(st, t->right, k1);
            }
        }

        return output;
    }
private:
    // Add each valid node to the stack until invalid value appears.
    void pushLeft(stack<TreeNode *> &st, TreeNode *root, int k1) {
        while (root != nullptr) {  // Push until invalid.
            st.emplace(root);
            if (root->val < k1) {
                break;
            }
            root = root->left;
        }
    }
};
