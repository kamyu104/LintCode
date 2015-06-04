// Time:  O(n^4)
// Space: O(n^3)

class Solution {
public:
    /**
     * @param s1 A string
     * @param s2 Another string
     * @return whether s2 is a scrambled string of s1
     */
    bool isScramble(string& s1, string& s2) {
        if (s1.length() != s2.length()) {
            return false;
        }

        if (s1 == s2) {
            return true;
        }

        const auto n = s1.length();

        // is_cramble[l][i][j] denoted as s1[i:i+l], s2[j:j+l] are scramble.
        vector<vector<vector<bool>>> 
            is_scramble(n + 1, vector<vector<bool>>(n, vector<bool>(n, false)));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s1[i] == s2[j]) {
                    is_scramble[1][i][j] = true;
                }
            }
        }

        // Compute by each length.
        for (int l = 2; l <= n; ++l) {
            for (int i = 0; i <  n - l + 1; ++i) {
                for (int j = 0; j < n - l + 1; ++j) {
                    for (int k = 1; k < l; ++k) {
                        if ((is_scramble[k][i][j] &&
                             is_scramble[l - k][i + k][j + k]) ||
                            (is_scramble[k][i][j + l - k] &&
                             is_scramble[l - k][i + k][j])) {
                            is_scramble[l][i][j] = true;
                            break; // Pruning.
                        }
                    }
                }
            }
        }

        return is_scramble[n][0][0];
    }
};
