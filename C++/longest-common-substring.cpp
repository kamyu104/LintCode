// Time:  O(m * n)
// Space: O(min(m, n))

class Solution {
public:
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        if (A.length() < B.length()) {
            return longestCommonSubstring(B, A);
        }

        // table[i][j] means the longest length of common substring
        // of A which ends with A[i - 1] and B which ends with B[j - 1].
        vector<vector<int>> table(2, vector<int>(A.length() + 1, 0));
        int longest = 0;

        // if A[i - 1] != B[j - 1]:
        //     table[i][j] = 0
        // if A[i - 1] == B[j - 1]:
        //     table[i][j] = table[i - 1][j - 1] + 1
        for (int i = 1; i < A.length() + 1; ++i) {
            for (int j = 1; j < B.length() + 1; ++j) {
                if (A[i - 1] != B[j - 1]) {
                    table[i % 2][j] = 0;
                } else {
                    table[i % 2][j] = table[(i - 1) % 2][j - 1] + 1;
                    longest = max(longest, table[i % 2][j]);
                }
            }
        }

        return longest;
    }
};

