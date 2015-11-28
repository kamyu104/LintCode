// Time:  O(m * n)
// Space: O(1)

class Solution {
public:
    /**
     * @param matrix a matrix of m x n elements
     * @return an integer array
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) {
            return result;
        }

        for (int left = 0, right = matrix[0].size() - 1,
                 top = 0, bottom = matrix.size() - 1;
             left <= right && top <= bottom;
             ++left, --right, ++top, --bottom) {

            for (int j = left; j <= right; ++j) {
                result.emplace_back(matrix[top][j]);
            }
            for (int i = top + 1; i < bottom; ++i) {
                result.emplace_back(matrix[i][right]);
            }
            for (int j = right; top < bottom && j >= left; --j) {
                result.emplace_back(matrix[bottom][j]);
            }
            for (int i = bottom - 1; left < right && i > top; --i) {
                result.emplace_back(matrix[i][left]);
            }
        }

        return result;
    }
};
