// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        if (str.length() > 256) {
            return false;
        }

        // At most 256 entires, const space.
        unordered_map<char, int> cnt;
        for (const auto& c : str) {
            ++cnt[c];
            if (cnt[c] > 1) {
                return false;
            }
        }

        return true;
    }
};
