// Time:  O(logn)
// Space: O(logn)

class Solution {
public:
    /**
     * @param x the base number
     * @param n the power number
     * @return the result
     */
    double myPow(double x, int n) {
        if (n < 0) {
            return 1 / myPow(x, -n);
        }
        return myPowRecu(x, n);
    }

    double myPowRecu(double x, int n) {
        if (n == 0) {
            return 1.0;
        }

        if (n % 2 == 0) {
            return myPowRecu(x * x, n / 2);
        } else {
            return x * myPowRecu(x * x, n / 2);
        }
    }
};
