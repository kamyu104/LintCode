// Time:  O(n)
// Space: O(1)

class Solution {
public:    
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    string minWindow(string &source, string &target) {
        if (source.empty() || source.length() < target.length()) {
            return "";
        }

        const int ASCII_MAX = 256;

        vector<int> exp_cnt(ASCII_MAX, 0);
        vector<int> cur_cnt(ASCII_MAX, 0);

        int cnt = 0;
        int start = 0;
        int min_start = 0;
        int min_width = numeric_limits<int>::max();

        for (const auto& c : target) {
            ++exp_cnt[c];
        }

        for (int i = 0; i < source.length(); ++i) {
            if (exp_cnt[source[i]] > 0) {
                ++cur_cnt[source[i]];
                if (cur_cnt[source[i]] <= exp_cnt[source[i]]) {  // Counting expected elements.
                    ++cnt;
                }
            }
            if (cnt == target.size()) {  // If window meets the requirement.
                while (exp_cnt[source[start]] == 0 ||  // Adjust left bound of window.
                       cur_cnt[source[start]] > exp_cnt[source[start]]) {
                    --cur_cnt[source[start]];
                    ++start;
                }

                if (min_width > i - start + 1) {  // Update minimum window.
                    min_width = i - start + 1;
                    min_start = start;
                }
            }
        }

        if (min_width == numeric_limits<int>::max()) {
            return "";
        }

        return source.substr(min_start, min_width);
    }
};
