// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
        int result = 0;
        while (n) {
            auto prev = result;
            result *= 10;
            result += n % 10;
            if (result / 10 != prev) {
                result = 0;
                break;
            }
            n /= 10;
        }
        return result;
    }
};
