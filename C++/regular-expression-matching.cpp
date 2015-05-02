// DP Solution with rolling window

// DP Solution

// Time:  O(m + n)
// Space: O(k), k is count of '*'
// Iteration solution
class Solution {
public:
    /**
     * @param s: A string
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        int p_pos = 0, s_pos = 0;
        int last_s_pos = -1, last_p_pos = -1;
        int s_len = strlen(s), p_len = strlen(p);
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
                last_pos.push({s_pos, p_pos});
            } else if (!last_pos.empty()) {
                // Rollback to the last position of '*' plus 2.
                // And try next position of last matched one.
                tie<int, int>(last_s_pos, last_p_pos) = last_pos.top();
                last_pos.pop();
                while (!last_pos.empty() && p[last_p_pos - 2] != s[last_s_pos] && p[last_p_pos - 2] != '.') {
                    tie<int, int>(last_s_pos, last_p_pos) = last_pos.top();
                    last_pos.pop();
                }
                if (p[last_p_pos - 2] == s[last_s_pos] || p[last_p_pos - 2] == '.') {
                    ++last_s_pos;
                    s_pos = last_s_pos;
                    p_pos = last_p_pos;
                    last_pos.push({s_pos, p_pos});
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

// Time:  O(m * n^2)
// Space: O(m + n)
// Recursion solution
class Solution4 {
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
