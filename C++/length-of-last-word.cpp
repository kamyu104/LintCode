// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        int counter = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            if(s[i] == ' ') {
                if (counter > 0) {
                    break;
                }
            } else {
                ++counter;
            }
        }
        return counter;
    }
};
