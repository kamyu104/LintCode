// Time:  O(m * n)
// Space: O(m)

// DP with rolling window.
class Solution {
public:
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        vector<vector<int>> ways(2, vector<int>(T.length() + 1, 0));
        // ways[i][j] means number of distinct subsequence of S[0, i] with T[0, j]
        ways[0][0] = 1;
        for (int i = 0; i < S.length(); ++i) {
            ways[(i + 1) % 2][0] = ways[i % 2][0];
            for (int j = 0; j < T.length(); ++j) {
                ways[(i + 1) % 2][j + 1] = S[i] == T[j]?
                                                ways[i % 2][j + 1] + ways[i % 2][j] :
                                                ways[i % 2][j + 1];

            }
        }
        return ways[S.length() % 2][T.length()];
    }
};

// Time:  O(m * n)
// Space: O(m * n)
// DP
class Solution2 {
public:
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        vector<vector<int>> ways(S.length() + 1, vector<int>(T.length() + 1, 0));
        // ways[i][j] means number of distinct subsequence of S[0, i] with T[0, j]
        ways[0][0] = 1;
        for (int i = 0; i < S.length(); ++i) {
            ways[i + 1][0] = ways[i][0];
            for (int j = 0; j < T.length(); ++j) {
                ways[i + 1][j + 1] = S[i] == T[j]?
                                          ways[i][j + 1] + ways[i][j] :
                                          ways[i][j + 1];

            }
        }
        return ways[S.length()][T.length()];
    }
};



