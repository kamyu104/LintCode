// Time:  O(n)
// Space: O(n)

class Solution {
public:
    /**
     * @param s : A string
     * @return : The length of the longest substring
     *           that contains at most k distinct characters.
     */
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> distinct;

        int start = 0;
        int max_len = 0;
        for (int i = 0; i < s.length(); ++i) {
            ++distinct[s[i]];
            while (distinct.size() > k) {
                --distinct[s[start]];
                if (distinct[s[start]] == 0) {
                    distinct.erase(s[start]);
                }
                ++start;
            }
            max_len = max(max_len, i - start + 1);
        }

        return max_len;
    }
};
