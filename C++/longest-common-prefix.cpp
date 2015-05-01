// Time:  O(n * k), k is the max length of strings
// Space: O(k)

// BFS
class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) {
            return "";
        }
        
        auto prefix_len = strs[0].length();
        for (int i = 0; i < prefix_len; ++i) {
            for (const auto& str : strs) {
                if (str[i] != strs[0][i]) {
                    prefix_len = i;
                    break;
                }
            }
        }
        
        return strs[0].substr(0, prefix_len);
    }
};

// DFS
class Solution2 {
public:
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) {
            return "";
        }
        
        auto prefix_len = strs[0].length();
        for (const auto& str : strs) {
            auto i = 0;
            for(; i < str.length() && i < prefix_len && str[i] == strs[0][i]; ++i);
            if (i < prefix_len) {
                prefix_len = i;
            }
        }
        
        return strs[0].substr(0, prefix_len);
    }
};
