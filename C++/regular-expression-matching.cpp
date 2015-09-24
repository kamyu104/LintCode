// Time:  O(m * n)
// Space: O(m)

// DP Solution with rolling window
class Solution {
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
        for (int i = 2; i <= p_len; ++i) {
            if (p[i - 1] == '*') {
                match[0 % 2][i] = match[0 % 2][i - 2];
            }
        }

        for (int i = 1; i <= s_len; ++i) {
            match[i % 2][0] = false;
            for (int j = 1; j <= p_len; ++j) {
                if (p[j - 1] != '*') {
                    match[i % 2][j] = match[(i - 1) % 2][j - 1] && (p[j - 1] == s[i - 1] || p[j - 1] == '.');
                } else {
                    match[i % 2][j] = j >= 2 && (match[i % 2][j - 2] || (match[(i - 1) % 2][j] && (p[j - 2] == s[i - 1] || p[j - 2]=='.')));
                }
            }
        }
        return match[s_len % 2][p_len];
    }
};

// Time:  O(m * n)
// Space: O(m * n)
// DP Solution
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
        vector<vector<bool>> match(s_len + 1, vector<bool>(p_len + 1));

        match[0][0] = true;
        for (int i = 2; i <= p_len; ++i) {
            if (p[i - 1] == '*') {
                match[0][i] = match[0][i - 2];
            }
        }

        for (int i = 1; i <= s_len; ++i) {
            match[i][0] = false;
            for (int j = 1; j <= p_len; ++j) {
                if (p[j - 1] != '*') {
                    match[i][j] = match[i - 1][j - 1] && (p[j - 1] == s[i - 1] || p[j - 1] == '.');
                } else {
                    match[i][j] = j >= 2 && (match[i][j - 2] || (match[i - 1][j] && (p[j - 2] == s[i - 1] || p[j - 2] == '.')));
                }
            }
        }
        return match[s_len][p_len];
    }
};

// Time:  O(m * n^2)
// Space: O(m + n)
// Recursion solution
class Solution3 {
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

        if (*(p + 1) == 0 || p[1] != '*') {
            if (*s != 0 && (p[0] == s[0] || p[0] == '.')) {
                // Matched a char.
                return isMatch(s + 1, p + 1);
            } else {
                return false;
            }
        } else {
            // Try all possible matches with '*' in p.
            while (*s != 0 && (p[0] == s[0] || p[0] == '.')) {
                if (isMatch(s, p + 2)) {
                    return true;
                }
                ++s;
            }
            return isMatch(s, p + 2);
        }
    }
};

// Time:  O(?)
// Space: O(?)
// Iteration solution (Greedy not work)
class Solution4 {
public:
    /**
     * @param s: A string
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        int p_pos = 0, s_pos = 0;
        int last_s_pos = -1, last_p_pos = -1;
        const int s_len = strlen(s), p_len = strlen(p);
        stack<pair<int, int>> last_pos;
        while (s_pos < s_len) {
            if (p_pos < p_len && (p_pos == p_len - 1 || p[p_pos + 1] != '*') &&
                (s_pos < s_len && (p[p_pos] == s[s_pos] || p[p_pos] == '.'))) {
                // Matched a char.
                ++s_pos;
                ++p_pos;
            } else if (p_pos < p_len && (p_pos != p_len - 1 && p[p_pos + 1] == '*')) {
                // Matched '*'.
                p_pos += 2;
                last_pos.emplace(make_pair(s_pos, p_pos));
            } else if (!last_pos.empty()) {
                // Rollback to the last position of '*' plus 2.
                // And try next position of last matched one.
                tie(last_s_pos, last_p_pos) = last_pos.top();
                last_pos.pop();
                while (!last_pos.empty() && p[last_p_pos - 2] != s[last_s_pos] && p[last_p_pos - 2] != '.') {
                    tie(last_s_pos, last_p_pos) = last_pos.top();
                    last_pos.pop();
                }
                if (p[last_p_pos - 2] == s[last_s_pos] || p[last_p_pos - 2] == '.') {
                    ++last_s_pos;
                    s_pos = last_s_pos;
                    p_pos = last_p_pos;
                    last_pos.emplace(make_pair(s_pos, p_pos));
                }
                else {
                    return false;
                }
            } else {
                // s_pos < s_len && no matched p, no position to retry.
                return false;
            }
        }

        // Skip '*' in p.
        while (p_pos < p_len - 1 && p[p_pos] == '.' && p[p_pos + 1] == '*') {
            p_pos += 2;
        }

        // Check if pattern is all matched.
        return p_pos == p_len;
    }
};
