// Time:  O(nlogn)
// Space: O(n)

// BIT solution. (281ms)
class Solution {
public:
   /**
     * @param A: An integer array
     * @return: Count the number of element before this element 'ai' is 
     *          smaller than it and return count number array
     */
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        // Get the place (position in the ascending order) of each number.
        vector<int> sorted_A(A), places(A.size());
        sort(sorted_A.begin(), sorted_A.end());
        for (int i = 0; i < A.size(); ++i) {
            places[i] = 
                lower_bound(sorted_A.begin(), sorted_A.end(), A[i]) -
                sorted_A.begin();
        }
        // Count the smaller elements before the number.
        vector<int> bit(A.size() + 1), ans(A.size());
        for (int i = 0; i < A.size(); ++i) {
            ans[i] = query(bit, places[i]);
            add(bit, places[i] + 1, 1);
        }
        return ans;
    }

private:
    void add(vector<int>& bit, int i, int val) {
        for (; i < bit.size(); i += lower_bit(i)) {
            bit[i] += val;
        }
    }

    int query(const vector<int>& bit, int i) {
        int sum = 0;
        for (; i > 0; i -= lower_bit(i)) {
            sum += bit[i];
        }
        return sum;
    }

    int lower_bit(int i) {
        return i & -i;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// Divide and Conqure solution. (653ms)
class Solution2 {
public:
   /**
     * @param A: An integer array
     * @return: Count the number of element before this element 'ai' is 
     *          smaller than it and return count number array
     */
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        vector<int> counts(A.size());
        vector<pair<int, int>> num_idxs;
        for (int i = 0; i < A.size(); ++i) {
            num_idxs.emplace_back(A[i], i);
        }
        countAndMergeSort(&num_idxs, 0, num_idxs.size() - 1, &counts);
        return counts;
    }

    void countAndMergeSort(vector<pair<int, int>> *num_idxs, int start, int end, vector<int> *counts) {
        if (end - start <= 0) {  // The number of range [start, end] of which size is less than 2 doesn't need sort.
            return;
        }
        int mid = start + (end - start) / 2;
        countAndMergeSort(num_idxs, start, mid, counts);
        countAndMergeSort(num_idxs, mid + 1, end, counts);

        int l = start;
        vector<pair<int, int>> tmp;
        for (int i = mid + 1; i <= end; ++i) {
            // Merge the two sorted arrays into tmp.
            while (l <= mid && (*num_idxs)[l].first < (*num_idxs)[i].first) {
                tmp.emplace_back((*num_idxs)[l++]);
            }
            tmp.emplace_back((*num_idxs)[i]);
            (*counts)[(*num_idxs)[i].second] += l - start;
        }
        while (l <= mid) {
            tmp.emplace_back((*num_idxs)[l++]);
        }
        // Copy tmp back to num_idxs.
        copy(tmp.begin(), tmp.end(), num_idxs->begin() + start);
    }
};

// Time:  O(nlogn)
// Space: O(n)
// BST solution. (743ms)
class Solution3 {
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
            BSTreeNode *node = new BSTreeNode(A[i], 0);
            root = insertNode(root, node);
            res.emplace_back(query(root, A[i]));
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
