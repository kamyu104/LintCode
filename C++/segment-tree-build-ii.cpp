// Time:  O(n)
// Space: O(h) = O(logn)

/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int>& A) {
        return buildRecu(A, 0, A.size() - 1);
    }

    SegmentTreeNode *buildRecu(const vector<int>& A, 
                               const int start, const int end) {
        if (start > end) {
            return nullptr;
        }
        // The root's start and end is given by build method.
        SegmentTreeNode *root = new SegmentTreeNode(start, end, INT_MAX);

        // If start equals to end, there will be no children for this node.
        if (start == end) {
            root->max = A[start];
            return root;
        }

        // Left child: start=A.left, end=(A.left + A.right) / 2.
        root->left = buildRecu(A, start, (start + end) / 2);

        // Right child: start=(A.left + A.right) / 2 + 1, end=A.right.
        root->right = buildRecu(A, (start + end) / 2 + 1, end);

        const int left_max = root->left != nullptr ? root->left->max : INT_MAX;
        const int right_max = root->right != nullptr ? root->right->max : INT_MAX;

        // Update max.
        root->max = max(left_max, right_max);
        return root;
    }
};
