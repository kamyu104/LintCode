// Time:  O(n)
// Space: O(1)

#include <bitset>

class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        bitset<256> lookup;
        for (const auto& c : str) {
            if (lookup[c]) {
                return false;
            }
            lookup.flip(c);
        }

        return true;
    }
};
