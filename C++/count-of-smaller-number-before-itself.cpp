// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    class BSTreeNode {
    public:
        int val, count;
        BSTreeNode *left, *right;
        BSTreeNode(int val, int count) {
            this->val = val;
            this->count = count;
            this->left = this->right = nullptr;
        }
    };
    /**
     * @param A: An integer array
     * @return: Count the number of element before this element 'ai' is
     *          smaller than it and return count number array
     */
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        vector<int> res;

        BSTreeNode *root = nullptr;

        // Insert into BST and get left count.
        for (int i = 0; i < A.size(); ++i) {
            int count = 0;
            BSTreeNode *node = new BSTreeNode(A[i], 0);
            root = insertNode(root, node);
            count = query(root, A[i]);
            res.emplace_back(count);
        }

        return res;
    }

    // Insert node into BST.
    BSTreeNode* insertNode(BSTreeNode* root, BSTreeNode* node) {
        if (root == nullptr) {
            return node;
        }
        BSTreeNode* curr = root;
        while (curr) {
            // Insert left if smaller.
            if (node->val < curr->val) {
                ++curr->count; // Increase the number of left children.
                if (curr->left != nullptr) {
                    curr = curr->left;
                } else {
                    curr->left = node;
                    break;
                }
            } else {  // Insert right if larger or equal.
                if (curr->right != nullptr) {
                    curr = curr->right;
                } else {
                    curr->right = node;
                    break;
                }
            }
        }
        return root;
    }

    // Query the smaller count of the value.
    int query(BSTreeNode* root, int val) {
        if (root == nullptr) {
            return 0;
        }
        int count = 0;
        BSTreeNode* curr = root;
        while (curr) {
            // Insert left.
            if (val < curr->val) {
                curr = curr->left;
            } else if (val > curr->val) {
                count += 1 + curr->count; // Count the number of the smaller nodes.
                curr = curr->right;
            } else {  // Equal.
                return count + curr->count;
            }
        }
        return 0;
    }
};
