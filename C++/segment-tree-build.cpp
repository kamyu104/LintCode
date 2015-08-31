// Time:  O(n)
// Space: O(h) = O(logn)

/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end) {
 *         this->start = start, this->end = end;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param start, end: Denote an segment / interval
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(int start, int end) {
        if (start > end) {
            return nullptr;
        }

        // The root's start and end is given by build method.
        SegmentTreeNode *root = new SegmentTreeNode(start, end);

        // If start equals to end, there will be no children for this node.
        if (start == end) {
            return root;
        }

        // Left child: start=A.left, end=(A.left + A.right) / 2.
        root->left = build(start, (start + end) / 2);

        // Right child: start=(A.left + A.right) / 2 + 1, end=A.right.
        root->right = build((start + end) / 2 + 1, end);

        return root;
    }
};
