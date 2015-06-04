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

        vector<int> expCnt(ASCII_MAX, 0);
        vector<int> curCnt(ASCII_MAX, 0);

        int cnt = 0;
        int start = 0;
        int min_width = INT_MAX;
        int min_start = 0;

        for (const auto& c : T) {
            ++expCnt[c];
        }

        for (int i = 0; i < source.length(); ++i) {
            if (expCnt[S[i]] > 0) {
                ++curCnt[S[i]];
                if (curCnt[S[i]] <= expCnt[S[i]]) { // Counting expected elements.
                    ++cnt;
                }
            }
            if (cnt == target.size()) { // If window meets the requirement
                while (expCnt[S[start]] == 0 || curCnt[S[start]] > expCnt[S[start]]) { // Adjust left bound of window
                    --curCnt[S[start]];
                    ++start;
                }

                if (min_width > i - start + 1) { // Update minimum window
                    min_width = i - start + 1;
                    min_start = start;
                }
            }
        }

        if (min_width == INT_MAX) {
            return "";
        }

        return source.substr(min_start, min_width);
    }
};

