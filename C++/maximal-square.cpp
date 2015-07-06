// Time:  O(m * n)
// Space: O(n)

class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int> > &matrix) {
        if (matrix.empty()) {
            return 0;
        }
        const int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> size(2, vector<int>(n, 0));
        int max_size = 0;

        for (int j = 0; j < n; ++j) {
            size[0][j] = matrix[0][j];
            max_size = max(max_size, size[0][j]);
        }
        for (int i = 1; i < m; ++i) {
            size[i % 2][0] = matrix[i][0];
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    size[i % 2][j] = min(size[i % 2][j - 1], 
                                         min(size[(i - 1) % 2][j], 
                                             size[(i - 1) % 2][j - 1])) + 1;
                    max_size = max(max_size, size[i % 2][j]);
                } else {
                    size[i % 2][j] = 0;
                }
            }
        }
        return max_size * max_size;
    }
};
