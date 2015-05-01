// Time:  build tree: O(n), query: O(h)
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
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        vector<int> res;
        
        // Build segment tree.
        SegmentTreeNode *root =build(A, 0, A.size() - 1);
        
        // Do each query.
        for (const auto& q : queries) {
            res.emplace_back(query(root, q.start, q.end));
        }
        
        return res;
    }
    
    
    // Build segment tree.
    SegmentTreeNode *build(vector<int> &A, int start, int end) {
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
        root->left = build(A, start, (start + end) / 2);
        
        // Right child: start=(A.left + A.right) / 2 + 1, end=A.right.
        root->right = build(A, (start + end) / 2 + 1, end);
        
        int left_min = root->left != nullptr? root->left->max : INT_MAX;
        int right_min = root->right != nullptr? root->right->max : INT_MAX;
        
        // Update min.
        root->max = min(left_min, right_min);
        return root;
    }
    
    
    // Query min in given range.
    int query(SegmentTreeNode *root, int start, int end) {
        // Out of range.
        if (root == nullptr || root->start > end || root->end <  start) {
            return INT_MAX;
        }
        
        // Current segment is totally within range [start, end]
        if (root->start >= start && root->end <= end) {
            return root->max;
        }
        
        int left = query(root->left, start, end);
        int right = query(root->right, start, end);
        
        // Find min in the children.
        return min(left, right);
    }
};
