// Time:  O(m * n)
// Space: O(min(m, n))

class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int>> &grid) {
        const int m = grid.size();
        const int n = grid[0].size();

        vector<vector<int>> sum(2, vector<int>(n, 0));
        sum[0][0] = grid[0][0];
        for (int j = 1; j < n; ++j) {
            sum[0][j] = sum[0][j - 1] + grid[0][j];
        }

        for (int i = 1; i < m; ++i) {
            sum[i % 2][0] = sum[(i - 1) % 2][0] + grid[i][0];
            for (int j = 1; j < n; ++j) {
                sum[i % 2][j] = min(sum[(i - 1) % 2][j], sum[i % 2][j - 1])
                                + grid[i][j];
            }
        }

        return sum[(m - 1) % 2][n - 1];
    }
};

