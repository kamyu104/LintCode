// Time:  O(m * n)
// Space: O(min(m, n))

class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        if (A.length() < B.length()) {
            return longestCommonSubsequence(B, A);
        }
        
        vector<vector<int>> dp(2, vector<int>(A.length() + 1, 0));
        
        // if A[i - 1] != B[j - 1]:
        //     dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
        // if A[i - 1] == B[j - 1]:
        //     dp[i][j] = dp[i - 1][j - 1] + 1
        for (int i = 1; i < A.length() + 1; ++i) {
            for (int j = 1; j < B.length() + 1; ++j) {
                if (A[i - 1] != B[j - 1]) {
                    dp[i % 2][j] = max(dp[(i - 1) % 2][j],
                                       dp[i % 2][j - 1]);
                } else {
                    dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
                }
            }
        }
        
        return dp[A.length() % 2][B.length()];
    }
};

