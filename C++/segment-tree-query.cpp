// Time:  O(h)
// Space: O(h)

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
     *@param root, start, end: The root of segment tree and
     *                         an segment / interval
     *@return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // Out of range.
        if (root == nullptr || root->start > end || root->end <  start) {
            return INT_MIN;
        }

        // Current segment is totally within range [start, end]
        if (root->start >= start && root->end <= end) {
            return root->max;
        }

        int left = query(root->left, start, end);
        int right = query(root->right, start, end);

        // Find max in the children.
        return max(left, right);
    }
};
