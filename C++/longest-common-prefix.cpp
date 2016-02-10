// Time:  O(n * k), k is the length of the common prefix
// Space: O(1)

// BFS
class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) {
            return "";
        }

        for (int i = 0; i < strs[0].length(); ++i) {
            for (const auto& str : strs) {
                if (i >= str.length() || str[i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

// Time:  O(n * l), l is the max length of strings
// Space: O(1)

// DFS
class Solution2 {
public:
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) {
            return "";
        }

        auto prefix_len = strs[0].length();
        for (const auto& str : strs) {
            auto i = 0;
            for (; i < str.length() && i < prefix_len && str[i] == strs[0][i]; ++i);
            if (i < prefix_len) {
                prefix_len = i;
            }
        }
        return strs[0].substr(0, prefix_len);
    }
};
