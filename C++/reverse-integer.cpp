// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
        long long result = 0;
        unsigned int temp = abs(n);
        while (temp > 0) {
            result *= 10;
            result += temp % 10;
            temp /= 10;
        }
        result = (n >= 0)? result : -result;
        result = (result > INT_MAX || result < INT_MIN)? 0 : result;
        return result;
    }
};
