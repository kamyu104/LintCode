// Time:  O(logm + logn)
// Space: O(1)

class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty()) {
            return false;
        }

        // Treat matrix as 1D array.
        const int m = matrix.size();
        const int n = matrix[0].size();
        int left = 0;
        int right = m * n - 1;

        // Find min of left s.t.  matrix[left / n][left % n] >= target
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[mid / n][mid % n] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // Check if matrix[left / n][left % n] equals to target.
        if (left != m * n && matrix[left / n][left % n] == target) {
            return true;
        }

        return false;
    }
};


class Solution2 {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty()) {
            return false;
        }

        // Treat matrix as 1D array.
        const int m = matrix.size();
        const int n = matrix[0].size();
        int left = 0;
        int right = m * n;

        // Find min of left s.t.  matrix[left / n][left % n] >= target
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (matrix[mid / n][mid % n] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        // Check if matrix[left / n][left % n] equals to target.
        if (left != m * n && matrix[left / n][left % n] == target) {
            return true;
        }

        return false;
    }
};

class Solution3 {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty()) {
            return false;
        }

        // Treat matrix as 1D array.
        const int m = matrix.size();
        const int n = matrix[0].size();
        int left = -1;
        int right = m * n;

        // Find min of right s.t.  matrix[right / n][right % n] >= target
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            if (matrix[mid / n][mid % n] >= target) {
                right = mid;
            } else {
                left = mid;
            }
        }

        // Check if matrix[right / n][right % n] equals to target.
        if (right != m * n && matrix[right / n][right % n] == target) {
            return true;
        }

        return false;
    }
};



