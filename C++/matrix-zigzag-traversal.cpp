// Time:  O(m * n)
// Space: O(1)

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int>> &matrix) {
        vector<int> zigzag;
        const int m = matrix.size(), n = matrix[0].size();

        for (int i = 0; i < m + n - 1; ++i) {
            if (i % 2) {
                for (int y = min(i, n - 1);  y >= max(0, i - m + 1); --y) {
                    zigzag.emplace_back(matrix[i - y][y]);
                }
            } else {
                for (int x = min(i, m - 1);  x >= max(0, i - n + 1); --x) {
                    zigzag.emplace_back(matrix[x][i - x]);
                }
            }
        }

        return zigzag;
    }
};

// Time:  O((m + n)^2)
// Space: O(1)

class Solution2 {
public:
    /**
     * @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int>> &matrix) {
        vector<int> zigzag;
        const size_t m = matrix.size(), n = matrix[0].size();

        for (int i = 0; i < m + n - 1; ++i) {
            if (i % 2 == 0) {
                for (int y = 0;  y < n; ++y) {
                    if (m > i - y && i - y >= 0) {
                        zigzag.emplace_back(matrix[i - y][y]);
                    }
                }
            } else {
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
