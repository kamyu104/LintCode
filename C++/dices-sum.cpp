// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    /**
     * @param n an integer
     * @return a list of pair<sum, probability>
     */
    vector<pair<int, double>> dicesSum(int n) {
        vector<pair<int, double>> result;
        vector<vector<double>> dp(2, vector<double>(6 * n + 1));

        for (int i = 1; i <= 6; ++i) {
            dp[1][i] = 1.0 / 6;
        }
        
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= 6 * i; ++j) {
                dp[i % 2][j] = 0.0;
                for (int k = 1; k <= 6; ++k) {
                    if (j > k) {
                        dp[i % 2][j] += dp[(i - 1) % 2][j - k];
                    }
                }
                dp[i % 2][j] /= 6.0;
            }
        }

        for (int i = n; i <= 6 * n; ++i) {
            result.emplace_back(i, dp[n % 2][i]);
        }

        return result;
    }
};
