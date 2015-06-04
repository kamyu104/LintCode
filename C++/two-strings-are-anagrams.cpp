// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> count;

        for (const auto& c: s) {
            ++count[tolower(c)];
        }

        for (const auto& c: t) {
            --count[tolower(c)];
            if (count[tolower(c)] < 0) {
                return false;
            }
        }

        return true;
    }
};
