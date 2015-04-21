// Time:  O(m * n)
// Space: O(1)

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int> > &matrix) {
        vector<int> zigzag;
        size_t m = matrix.size(), n = matrix[0].size();
        
        for (int i = 0; i < m + n - 1; ++i) {
            if (i % 2 == 0) {
                for (int y = 0;  y < n; ++y) {
                    if (m > i - y && i - y >= 0) {
                        zigzag.emplace_back(matrix[i - y][y]);
                    }
                }
            }
            else {
                for (int x = 0; x < m; ++x) {
                    if (n > i - x && i - x >= 0) {
                        zigzag.emplace_back(matrix[x][i - x]);
                    }
                }
            }
        }
        
        return zigzag;
    }
};