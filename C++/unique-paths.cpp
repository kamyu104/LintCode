// Time:  O(min(m, n))
// Space: O(1)

// Use combination in math.
class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        return combination(m + n - 2, min(m - 1, n - 1));
    }

    int combination(int  n, int k) {
        long long count = 1;
        // C(n, k) = (n) / 1 * (n - 1) / 2 ... * (n - k + 1) / k
        for (int i = 1; i <= k; ++i, --n) {
            count = count * n / i;
        }

        return count;
    }
};

// Time:  O(m * n)
// Space: O(min(m, n))
// DP solution with rolling window.
class Solution2 {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        if (m < n) {
            return uniquePaths(n, m);
        }

        vector<vector<int>> path(2, vector<int>(n, 0));

        for (int j = 0; j < n; ++j) {
            path[0 % 2][j] = 1;
        }

        for (int i = 1; i < m; ++i) {
            path[i % 2][0] = path[(i - 1) % 2][0];
            for (int j = 1; j < n; ++j) {
                path[i % 2][j] = path[(i - 1) % 2][j] + path[i % 2][j - 1];
            }
        }

        return path[(m - 1) % 2][n - 1];
    }
};

// Time:  O(m * n)
// Space: O(m * n)
// DP solution.
class Solution3 {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        if (m < n) {
            return uniquePaths(n, m);
        }

        vector<vector<int>> path(m, vector<int>(n, 0));

        for (int j = 0; j < n; ++j) {
            path[0][j] = 1;
        }

        for (int i = 1; i < m; ++i) {
            path[i][0] = path[i - 1][0];
            for (int j = 1; j < n; ++j) {
                path[i][j] = path[i - 1][j] + path[i][j - 1];
            }
        }

        return path[m - 1][n - 1];
    }
};

