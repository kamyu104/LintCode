// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    /**
     * @param dividend the dividend
     * @param divisor the divisor
     * @return the result
     */
    int divide(int dividend, int divisor) {
        // Handle corner case.
        if (divisor == INT_MIN) {
            return dividend == divisor ? 1 : 0;
        } else if (!divisor || divisor == -1 && dividend == INT_MIN) {
            return INT_MAX;
        } else if (divisor == 1) {
            return dividend;
        }
        
        bool negative = (dividend > 0) ^ (divisor > 0);
        if (dividend > 0) {
            dividend = -dividend;
        }
        if (divisor > 0) {
            divisor = -divisor;
        }
        vector<int> multipliers, products;
        multipliers.push_back(1);
        products.push_back(divisor);
        int idx = 1, res = 0;
        while (products[idx - 1] < 0 && idx < 32) {
            products.push_back(divisor << idx);
            multipliers.push_back(1 << idx);
            ++idx;
        }
        idx -= 2;
        while (dividend <= divisor) {
            if (dividend <= products[idx]) {
                res += multipliers[idx];
                dividend -= products[idx];
            }
            --idx;
        }
        return negative ? -res : res;
    }
};
