// Time:  O(k * n * t)
// Space: O(n * t)

class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    int kSum(vector<int> A, int k, int target) {
        const int n = A.size();

        // table[i][j][t] denotes the number of ways to select,
        // from first i elements, j elements whose sum equals to t
        vector<vector<vector<int>>> table(2, vector<vector<int>>(n + 1, vector<int>(target + 1, 0)));

        for (int i = 1; i <= n; ++i) {
            if (A[i - 1] <= target) {
                for (int j = i; j <= n; ++j) {
                    table[1][j][A[i - 1]] = 1;
                }
            }
        }

        for (int i = 2; i <= k; ++i) {
            for (int j = i; j <= n; ++j) {
                for (int p = 1; p <= target; ++p) {
                    table[i % 2][j][p] = 0;
                    if (i < j) {
                        table[i % 2][j][p] = table[i % 2][j - 1][p];
                    }
                    if (p - A[j - 1] >= 0) {
                        table[i % 2][j][p] += table[(i - 1) % 2][j - 1][p - A[j - 1]];
                    }
                }
            }
        }

        return table[k % 2][n][target];
    }
};

// Time:  O(k * n * t)
// Space: O(k * n * t)
class Solution2 {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    int kSum(vector<int> A, int k, int target) {
        const int n = A.size();

        // table[i][j][t] denotes the number of ways to select,
        // from first i elements, j elements whose sum equals to t
        vector<vector<vector<int>>> table(n+1, vector<vector<int>>(k + 1, vector<int>(target + 1, 0)));

        for (int i = 1; i <= n; ++i) {
            if (A[i - 1] <= target)
            {
                for (int j = i; j <= n; ++j) {
                    table[j][1][A[i - 1]] = 1;
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = min(i, k); j > 1; --j) {
                for (int p = 1; p <= target; ++p) {
                    table[i][j][p] = table[i - 1][j][p];
                    if (p - A[i - 1] >= 0) {
                        table[i][j][p] += table[i - 1][j - 1][p - A[i - 1]];
                    }
                }
            }
        }

        return table[n][k][target];
    }
};

// Time:  O(C(n, k))
// Space: O(k)
class Solution_TLE {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    int kSum(vector<int> A, int k, int target) {
        int ans = 0;
        helper(A, k, 0, target, ans);
        return ans;
    }

    void helper(vector<int> A, int k, int start, int target, int & ans) {
        if (k < 0 || target < 0) return;

        if (k == 0 && target == 0) {
            ++ans;
            return;
        }

        for (int i = start; i <= A.size() - k; i++)
            helper(A, k - 1, i + 1, target - A[i], ans);
    }
};
