// Time:  O(n * klogk), k is max length of strings
// Space: O(m), m is number of anagram groups

class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, int> table;

        for (auto str : strs) {
            sort(str.begin(), str.end());
            ++table[str];
        }

        vector<string> anagrams;
        for (const auto& str : strs) {
            string sorted_str(str);
            sort(sorted_str.begin(), sorted_str.end());
            if (table[sorted_str] >= 2) {
                anagrams.emplace_back(str);
            }
        }

        return anagrams;
    }
};

