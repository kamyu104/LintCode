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
     *@param root, index, value: The root of segment tree and
     *@ change the node's value with [index, index] to the new given value
     *@return: void
     */
    void modify(SegmentTreeNode *root, int index, int value) {
        // Out of range.
        if (root == nullptr || root->start > index || root->end < index) {
            return;
        }

        // Change the node's value with [index, index] to the new given value.
        if (root->start == index && root->end == index) {
            root->max = value;
            return;
        }

        modify(root->left, index, value);
        modify(root->right, index, value);

        int left_max = root->left != nullptr? root->left->max : INT_MIN;
        int right_max = root->right != nullptr? root->right->max : INT_MIN;

        // Update max.
        root->max = max(left_max, right_max);
    }
};
