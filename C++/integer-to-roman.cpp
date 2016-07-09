// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param n The integer
     * @return Roman representation
     */
    string intToRoman(int n) {
        const vector<int> nums{1000, 900, 500, 400, 100, 90,
                               50, 40, 10, 9, 5, 4, 1};
        const vector<string> romans{"M", "CM", "D", "CD", "C", "XC", "L",
                                    "XL", "X", "IX", "V", "IV", "I"};

        string result;
        int i = 0;
        while (n > 0) {
            int times = n / nums[i];
            while (times--) {
                n -= nums[i];
                result.append(romans[i]);
            }
            ++i;
        }        
        return result;
    }
};
