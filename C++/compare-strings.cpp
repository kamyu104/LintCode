// Time:  O(n)
// Space: O(c)

// len(A) is much larger than len(B), this solution is better
class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true
     *           else return false
     */
    bool compareStrings(string A, string B) {
        unordered_map<char, int> h;
        for (const auto& c: B) {
            ++h[c];
        }

        size_t cnt = B.length();
        for (const auto& c: A) {
            if (h[c] > 0) {
                --h[c];
                --cnt;
            }
            if (cnt == 0) {
                return true;
            }
        }

        if (cnt > 0) {
            return false;
        }

        return true;
    }
};

class Solution2 {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        unordered_map<char, int> h;
        for (const auto& c: A) {
            ++h[c];
        }

        for (const auto& c: B) {
            if (--h[c] < 0) {
                return false;
            }
        }

        return true;
    }
};

