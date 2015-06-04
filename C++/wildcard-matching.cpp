// Time:  O(m + n), m is length of pattern, n is length of string
// Space: O(1)

// Iteration with greedy
class Solution {
public:
    /**
     * @param s: A string
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        int p_pos = 0, s_pos = 0;
        int last_s_pos = -1, last_p_pos = -1;
        const int s_len = strlen(s), p_len = strlen(p);
        while (s_pos < s_len) {
            if (p_pos < p_len && (p[p_pos] == s[s_pos] || p[p_pos] == '?')) {
                // Matched a char.
                ++s_pos;
                ++p_pos;
            } else if (p_pos < p_len && p[p_pos] == '*') {
                // Matched '*'.
                ++p_pos;
                last_s_pos = s_pos;
                last_p_pos = p_pos;
            } else if (last_p_pos != -1) {
                // Rollback to the last position of '*' plus 1.
                // And try next position of last matched one.
                ++last_s_pos;
                s_pos = last_s_pos;
                p_pos = last_p_pos;
            } else {
                // s_pos < s_len && no matched p, no position to retry.
                return false;
            }
        }

        // Skip '*' in p.
        while (p_pos < p_len && p[p_pos] == '*') {
            ++p_pos;
        }

        // Check if pattern is all matched.
        return p_pos == p_len;
    }
};

// Time:  O(m * n), m is length of pattern, n is length of string
// Space: O(m)

// DP solution with rolling window
class Solution2 {
public:
    /**
     * @param s: A string
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        const size_t s_len = strlen(s);
        const size_t p_len = strlen(p);

        // match[i][j] denotes as:
        // s[0, i - 1] matches p[0, j - 1] or not.
        vector<vector<bool>> match(2, vector<bool>(p_len + 1));

        match[0][0] = true;
        for (int i = 1; i <= p_len; ++i) {
            if (p[i - 1] == '*') {
                match[0 % 2][i] = match[0 % 2][i - 1];
            }
        }

        for (int i = 1; i <= s_len; ++i) {
            match[i % 2][0] = false;
            for (int j = 1; j <= p_len; ++j) {
                if (p[j - 1] != '*') {
                    match[i % 2][j] = match[(i - 1) % 2][j - 1]
                    && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
                }
                else {
                    match[i % 2][j] = match[i % 2][j - 1] || match[(i - 1) % 2][j];
                }
            }
        }
        return match[s_len % 2][p_len];
    }
};

// Time:  O(m * n), m is length of pattern, n is length of string
// Space: O(m * n)

// DP solution
class Solution3 {
public:
    /**
     * @param s: A string
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        const size_t s_len = strlen(s);
        const size_t p_len = strlen(p);

        // match[i][j] denotes as:
        // s[0, i - 1] matches p[0, j - 1] or not.
        vector<vector<bool>> match(s_len + 1, vector<bool>(p_len + 1));

        match[0][0] = true;
        for (int i = 1; i <= p_len; ++i) {
            if (p[i - 1] == '*') {
                match[0][i] = match[0][i - 1];
            }
        }

        for (int i = 1; i <= s_len; ++i) {
            match[i][0] = false;
            for (int j = 1; j <= p_len; ++j) {
                if (p[j - 1] != '*') {
                    match[i][j] = match[i - 1][j - 1]
                    && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
                }
                else {
                    match[i][j] = match[i][j - 1] || match[i - 1][j];
                }
            }
        }
        return match[s_len][p_len];
    }
};

// Time:  O(m * n^2)
// Space: O(m + n)
// Recursion
class Solution_TLE {
public:
    /**
     * @param s: A string
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        if (*s == 0 || *p == 0) {
            return *s == 0 && *p == 0;
        }

        if (p[0] != '*') {
            if (p[0] == s[0] || p[0] == '?') {
                // Matched a char.
                return isMatch(s + 1, p + 1);
            } else {
                return false;
            }
        } else {
            // Try all possible matches with '*' in p.
            while (*s != 0) {
                if (isMatch(s, p + 1)) {
                    return true;
                }
                ++s;
            }
            return isMatch(s, p + 1);
        }
    }
};
