// Time:  build tree: O(n), query: O(h), modify: O(h)
// Space: O(h)

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */

class SegmentTreeSumNode {
public:
    int start, end;
    long long sum;
    SegmentTreeSumNode *left, *right;
    SegmentTreeSumNode(int start, int end, long long sum) {
        this->start = start;
        this->end = end;
        this->sum = sum;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /* you may need to use some attributes here */
    SegmentTreeSumNode *root_;

    /**
     * @param A: An integer vector
     */
    Solution(vector<int> A) {
        root_ = build(A, 0, A.size() - 1);
    }

    /**
     * @param start, end: Indices
     * @return: The sum from start to end
     */
    long long query(int start, int end) {
        queryTree(root_, start, end);
    }

    /**
     * @param index, value: modify A[index] to value.
     */
    void modify(int index, int value) {
        modifyTree(root_, index, value);
    }

    // Query Sum in given range.
    long long queryTree(SegmentTreeSumNode *root, int start, int end) {
        // Out of range.
        if (root == nullptr || root->start > end || root->end <  start) {
            return 0;
        }

        // Current segment is totally within range [start, end]
        if (root->start >= start && root->end <= end) {
            return root->sum;
        }

        long long left = queryTree(root->left, start, end);
        long long right = queryTree(root->right, start, end);

        // Find sum in the children.
        return left + right;
    }


    void modifyTree(SegmentTreeSumNode *root, int index, int value) {
        // Out of range.
        if (root == nullptr || root->start > index || root->end < index) {
            return;
        }

        // Change the node's value with [index, index] to the new given value.
        if (root->start == index && root->end == index) {
            root->sum = value;
            return;
        }

        modifyTree(root->left, index, value);
        modifyTree(root->right, index, value);

        int left_sum = root->left != nullptr? root->left->sum : 0;
        int right_sum = root->right != nullptr? root->right->sum : 0;

        // Update sum.
        root->sum = left_sum + right_sum;
    }

    // Build segment tree.
    SegmentTreeSumNode *build(vector<int> &A, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        // The root's start and end is given by build method.
        SegmentTreeSumNode *root = new SegmentTreeSumNode(start, end, 0);

        // If start equals to end, there will be no children for this node.
        if (start == end) {
            root->sum = A[start];
            return root;
        }

        // Left child: start=A.left, end=(A.left + A.right) / 2.
        root->left = build(A, start, (start + end) / 2);

        // Right child: start=(A.left + A.right) / 2 + 1, end=A.right.
        root->right = build(A, (start + end) / 2 + 1, end);

        long long left_sum = root->left != nullptr? root->left->sum : 0;
        long long right_sum = root->right != nullptr? root->right->sum : 0;

        // Update sum.
        root->sum = left_sum + right_sum;
        return root;
    }
};


