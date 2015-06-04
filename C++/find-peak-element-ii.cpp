// Time:  O(m + n)
// Space: O(1)

class Solution { 
public:
    /**
     * @param A: An integer matrix
     * @return: The index of the peak
     */
    vector<int> findPeakII(vector<vector<int>> A) {
        int upper = 0, down = A.size() - 1;
        int left = 0, right = A[0].size() - 1;

        while (upper < down && left < right) {
            int height = down - upper + 1;
            int width = right - left + 1;

            // T(m, n) = T(m, n / 2) + O(m) = T(m / 2, n / 2) + O(m) + O(n / 2) = ... = O(2m) + O(2n) = O(max(m, n))
            if (width > height) {  // Vertical split.
                int mid_j = left + (right - left) / 2;
                int left_max = 0, central_max = 0, right_max = 0;
                int max_i = -1, max_j = -1;
                for (int i = upper + 1; i < down; ++i) {
                    if (A[i][mid_j] > central_max) {
                        max_i = i, max_j = mid_j;
                        central_max = A[i][mid_j];
                    }
                    left_max = max(left_max, A[i][mid_j - 1]);
                    right_max = max(right_max, A[i][mid_j +  1]);
                }
                if (left_max > central_max && left_max > right_max) {  // Find left.
                    right = mid_j;
                } else if (right_max > central_max && right_max > left_max) {  // Find right.
                    left = mid_j;
                } else {  // Find one peak.
                    return {max_i, max_j};
                }
            } else {  // Horizontal split.
                int mid_i = upper + (down - upper) / 2;
                int upper_max = 0, central_max = 0, down_max = 0;
                int max_i = -1, max_j = -1;
                for (int j = left + 1; j < right; ++j) {
                    if (A[mid_i][j] > central_max) {
                        max_i = mid_i, max_j = j;
                        central_max = A[mid_i][j];
                    }
                    upper_max = max(upper_max, A[mid_i - 1][j]);
                    down_max = max(down_max, A[mid_i + 1][j]);
                }
                if (upper_max > central_max && upper_max > down_max) {  // Find upper.
                    down = mid_i;
                } else if (down_max > central_max && down_max > upper_max) {  // Find down.
                    upper = mid_i;
                } else {  // Find one peak.
                    return {max_i, max_j};
                }
            } 

        }
        return {-1, -1}; // Not found.
    }
};

// Although this solution passes current LintCode test cases,
// it may fail to find the peak like the following case:
// A = {{ 1,  2,  3,  4,  5},
//      { 6, 22, 23, 28,  7},
//      { 8, 24, 25, 26,  9},
//      {10, 11, 12, 13, 14}};
class Solution_Wrong {
public:
    /**
     * @param A: An integer matrix
     * @return: The index of the peak
     */
    bool isPeak(const vector<vector<int>> &A, const int i, const int j) {
        if (i < 1 || i >= A.size() - 1 || j < 1 || j >= A[0].size() - 1) {
            return false;
        }

        return A[i][j] > A[i][j - 1] && A[i][j] > A[i - 1][j] &&
               A[i][j] > A[i][j + 1] && A[i][j] > A[i + 1][j];
    }

    vector<int> findPeakII(vector<vector<int>> A) {
        int i = 1, j = 1;
        while (i < A.size() - 1 && j < A[0].size() - 1) {
            if (isPeak(A, i, j)) {
                return {i, j};
            } else {
                if (A[i + 1][j] > A[i][j + 1]) {
                    ++i;
                } else {
                    ++j;
                }
            }
        }
        return {-1, -1};
    }
};


