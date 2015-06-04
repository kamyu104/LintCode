// Time:  O(logn), per query
// Space: O(h), per query

/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, count;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int count) {
 *         this->start = start;
 *         this->end = end;
 *         this->count = count;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

// Segment tree solution.
class Solution {
public:
    /**
     * @param A: An integer array
     * @return: The number of element in the array that
     *          are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        vector<int> res;

        // Sort array before building segment tree.
        sort(A.begin(), A.end());

        // Build segment tree.
        SegmentTreeNode *root = build(A, 0, A.size() - 1);

        // Do each query.
        for (const auto& q : queries) {
            res.emplace_back(query(root, 0, A.size() - 1, A, q));
        }

        return res;
    }

    // Build segment tree.
    SegmentTreeNode *build(vector<int> &A, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        // The root's start and end is given by build method.
        SegmentTreeNode *root = new SegmentTreeNode(start, end, 0);

        // If start equals to end, there will be no children for this node.
        if (start == end) {
            root->count = 1;
            return root;
        }

        // Left child: start=A.left, end=(A.left + A.right) / 2.
        root->left = build(A, start, (start + end) / 2);

        // Right child: start=(A.left + A.right) / 2 + 1, end=A.right.
        root->right = build(A, (start + end) / 2 + 1, end);

        int left_count = root->left != nullptr? root->left->count : 0;
        int right_count = root->right != nullptr? root->right->count : 0;

        // Update count.
        root->count = left_count + right_count;
        return root;
    }


    // Query count in given range.
    int query(SegmentTreeNode *root, int start, int end,
                    vector<int> &A, int q) {
        // Out of range.
        if (root == nullptr || root->start > end || root->end <  start) {
            return 0;
        }

        // Skip the segment where q is smaller than its start.
        if (q <= A[root->start]) {
            return 0;
        }

        // Current segment is totally smaller than q.
        if (q > A[root->end]) {
            return root->count;
        }

        int left = query(root->left, start, end, A, q);
        int right = query(root->right, start, end, A, q);

        // Find count in the children.
        return left + right;
    }
};


// Time:  O(logn)
// Space: O(1)
// Binary search solution.
class Solution2 {
public:
    /**
     * @param A: An integer array
     * @return: The number of element in the array that
     *          are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        vector<int> result;
        sort(A.begin(), A.end());
        for (int i = 0; i < queries.size(); ++i) {
            const auto it = lower_bound(A.cbegin(), A.cend(), queries[i]);
            result.emplace_back(it - A.cbegin());
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(1)
// Loop solution.
class Solution_TLE {
public:
    /**
     * @param A: An integer array
     * @return: The number of element in the array that
     *          are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        vector<int> result(queries.size(), 0);
        for (auto& x : A) {
            for (int i = 0; i < queries.size(); ++i) {
                if (queries[i] > x) {
                    ++result[i];
                }
            }
        }
        return result;
    }
};
