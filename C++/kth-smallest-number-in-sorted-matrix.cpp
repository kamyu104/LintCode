// Time:  O(klog(min(m, n, k))
// Space: O(min(m, n, k))

// BST solution.
class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        if (matrix.size() < matrix[0].size()) {  // Height is smaller.
            return horizontal_search(matrix, k);
        } else {  // Width is smaller.
            return vertical_search(matrix, k);
        }
    }

    int horizontal_search(const vector<vector<int>> &matrix, int k) {
        multimap<int, pair<int, int>> min_bst;

        // Init BST by the first element of the first kth row.
        for (int i = 0; i < min(static_cast<int>(matrix.size()), k); ++i) {
            min_bst.emplace(pair<int, pair<int, int>>{matrix[i][0], {i, 0}});
        }

        int kth_smallest = INT_MAX;
        while (!min_bst.empty() && k--) {
            // Pop the min of BST.
            if (k == 0) {
                kth_smallest = min_bst.cbegin()->first;
            }
            // Pop the min of BST.
            int i = min_bst.cbegin()->second.first;
            int j = min_bst.cbegin()->second.second;
            min_bst.erase(min_bst.cbegin());

            // Insert the next possible element.
            if (j + 1 < matrix[i].size()) {
                min_bst.emplace(pair<int, pair<int, int>>{matrix[i][j + 1], {i, j + 1}});
            }
        }

        return kth_smallest;
    }

    int vertical_search(const vector<vector<int>> &matrix, int k) {
        multimap<int, pair<int, int>> min_bst;

        // Init BST by the first element of the first kth column.
        for (int j = 0; j < min(static_cast<int>(matrix[0].size()), k); ++j) {
            min_bst.emplace(pair<int, pair<int, int>>{matrix[0][j], {0, j}});
        }

        int kth_smallest = INT_MAX;
        while (!min_bst.empty() && k--) {
            // Pop the min of Heap.
            if (k == 0) {
                kth_smallest = min_bst.cbegin()->first;
            }
            // Pop the min of BST.
            int i = min_bst.cbegin()->second.first;
            int j = min_bst.cbegin()->second.second;
            min_bst.erase(min_bst.cbegin());

            // Insert the next possible element.
            if (i + 1 < matrix.size()) {
                min_bst.emplace(pair<int, pair<int, int>>{matrix[i + 1][j], {i + 1, j}});
            }
        }

        return kth_smallest;
    }
};

// Time:  O(klog(min(m, n, k))
// Space: O(min(m, n, k))
// Heap solution.
class Solution2 {
public:
    struct Compare {
        bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
            return a.first > b.first;
        }
    };
    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        if (matrix.size() < matrix[0].size()) {  // Height is smaller.
            return horizontal_search(matrix, k);
        } else {  // Width is smaller.
            return vertical_search(matrix, k);
        }
    }

    int horizontal_search(const vector<vector<int>> &matrix, int k) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Compare> min_heap;

        // Init Heap by the first element of the first kth row.
        for (int i = 0; i < min(static_cast<int>(matrix.size()), k); ++i) {
            min_heap.emplace(pair<int, pair<int, int>>{matrix[i][0], {i, 0}});
        }

        int kth_smallest = INT_MAX;
        while (!min_heap.empty() && k--) {
            // Pop the min of Heap.
            if (k == 0) {
                kth_smallest = min_heap.top().first;
            }
            kth_smallest = min_heap.top().first;
            int i = min_heap.top().second.first;
            int j = min_heap.top().second.second;
            min_heap.pop();

            // Insert the next possible element.
            if (j + 1 < matrix[i].size()) {
                min_heap.emplace(pair<int, pair<int, int>>{matrix[i][j + 1], {i, j + 1}});
            }
        }

        return kth_smallest;
    }

    int vertical_search(const vector<vector<int>> &matrix, int k) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Compare> min_heap;

        // Init Heap by the first element of the first kth column.
        for (int j = 0; j < min(static_cast<int>(matrix[0].size()), k); ++j) {
            min_heap.emplace(pair<int, pair<int, int>>{matrix[0][j], {0, j}});
        }

        int kth_smallest = INT_MAX;
        while (!min_heap.empty() && k--) {
            // Pop the min of Heap.
            if (k == 0) {
                kth_smallest = min_heap.top().first;
            }
            int i = min_heap.top().second.first;
            int j = min_heap.top().second.second;
            min_heap.pop();

            // Insert the next possible element.
            if (i + 1 < matrix.size()) {
                min_heap.emplace(pair<int, pair<int, int>>{matrix[i + 1][j], {i + 1, j}});
            }
        }

        return kth_smallest;
    }
};
