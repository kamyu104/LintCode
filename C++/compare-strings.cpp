// Time:  O(n)
// Space: O(c)

class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        unordered_map<char, size_t> h;
        for (auto& c: B) {
            ++h[c];
        }
        
        size_t cnt = B.length();
        for (auto& c: A) {
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

