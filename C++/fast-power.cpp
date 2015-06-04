// Time:  O(logn)
// Space: O(logn)

class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        return longFastPower(a % b, b, n);
    }

    long long longFastPower(long long a, int b, int n) {
        if (n == 0) {
            return 1 % b;
        }
        if (n % 2 == 1) {
            return (a * longFastPower((a * a) % b, b, n / 2)) % b;
        }
        else {
            return longFastPower((a * a) % b, b, n / 2);
        }
    }
};
