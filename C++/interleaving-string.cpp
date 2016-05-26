// Time:  O(m * n)
// Space: O(min(m, n))

// DP with rolling window.
class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        // Early return if |s1| + |s2| != |s3|.
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        if (s1.size() < s2.size()) {
            return isInterleave(s2, s1, s3);
        }

        vector<deque<bool>> T(2, deque<bool>(s2.size() + 1));
        T[0][0] = true;  // Base case.

        // Uses chars from s2 only to match s3.
        for (size_t j = 0; j < s2.size(); ++j) {
            if (s2[j] == s3[j]) {
                T[0][j + 1] = true;
            } else {
                break;
            }
        }

        for (size_t i = 0; i < s1.size(); ++i) {
            // Uses chars from s1 only to match s3.
            T[(i + 1) % 2][0] = T[i % 2][0] && s1[i] == s3[i];

            for (size_t j = 0; j < s2.size(); ++j) {
                T[(i + 1) % 2][j + 1] = (T[i % 2][j + 1] && s1[i] == s3[i + j + 1]) ||
                                        (T[(i + 1) % 2][j] && s2[j] == s3[i + j + 1]);
            }
        }

        return T[s1.size() % 2][s2.size()];
    }
};

// Time:  O(m * n)
// Space: O(m * n)
// DP
class Solution2 {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        // Early return if |s1| + |s2| != |s3|.
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        vector<deque<bool>> T(s1.size() + 1, deque<bool>(s2.size() + 1));
        T[0][0] = true;  // Base case.
        // Uses chars from s1 only to match s3.
        for (size_t i = 0; i < s1.size(); ++i) {
            if (s1[i] == s3[i]) {
                T[i + 1][0] = true;
            } else {
                break;
            }
        }
        // Uses chars from s2 only to match s3.
        for (size_t j = 0; j < s2.size(); ++j) {
            if (s2[j] == s3[j]) {
                T[0][j + 1] = true;
            } else {
                break;
            }
        }

        for (size_t i = 0; i < s1.size(); ++i) {
            for (size_t j = 0; j < s2.size(); ++j) {
                T[i + 1][j + 1] = (T[i][j + 1] && s1[i] == s3[i + j + 1]) ||
                                  (T[i + 1][j] && s2[j] == s3[i + j + 1]);
            }
        }

        return T[s1.size()][s2.size()];
    }
};
