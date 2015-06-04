// Time:  O(m * n)
// Space: O(min(m, n))

// DP with rolling window
class Solution {
public:
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        const size_t m = word1.size();
        const size_t n = word2.size();

        if (m < n) {
            return minDistance(word2, word1);
        }

        vector<vector<int>> steps(2, vector<int>(n + 1, 0));

        for (int j = 0; j < n + 1; ++j) {
            steps[0][j] = j;
        }

        for (int i = 1; i < m + 1; ++i) {
            steps[i % 2][0] = i;
            for (int j = 1; j < n + 1; ++j) {
                steps[i % 2][j] = word1[i - 1] == word2[j - 1] ?
                steps[(i - 1) % 2][j - 1] :
                1 + min(steps[(i - 1) % 2][j - 1],
                        min(steps[(i - 1) % 2][j], steps[i % 2][j - 1]));
            }
        }

        return steps[m % 2][n];
    }
};

// Time:  O(m * n)
// Space: O(m * n)
// DP
class Solution2 {
public:
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        const size_t m = word1.size();
        const size_t n = word2.size();

        if (m < n) {
            return minDistance(word2, word1);
        }

        vector<vector<int>> steps(m + 1, vector<int>(n + 1, 0));

        for (int j = 0; j < n + 1; ++j) {
            steps[0][j] = j;
        }

        for (int i = 1; i < m + 1; ++i) {
            steps[i][0] = i;
            for (int j = 1; j < n + 1; ++j) {
                steps[i][j] = word1[i - 1] == word2[j - 1] ?
                steps[i - 1][j - 1] :
                1 + min(steps[i - 1][j - 1],
                        min(steps[i - 1][j], steps[i][j - 1]));
            }
        }

        return steps[m][n];
    }
};
