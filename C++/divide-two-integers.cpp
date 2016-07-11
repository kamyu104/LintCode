// Time:  O(logn) = O(1)
// Space: O(1)

// Only using integer type.
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
            return numeric_limits<int>::max();
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

        int product = divisor;
        int idx = 1;
        while (product < 0 && idx < 32) {
            ++idx;
            product <<= 1;
        }
        idx -= 2; // Skip value of INT_MIN
        product = divisor << idx;
        int multiplier = 1 << idx;

        int res = 0;
        while (dividend <= divisor) {
            if (dividend <= product) {
                res += multiplier;
                dividend -= product;
            }
            --idx;
            product = divisor << idx;
            multiplier >>= 1;
        }
        return negative ? -res : res;
    }
};

// Time:  O(logn) = O(1)
// Space: O(1)
// Using long long type.
class Solution2 {
public:
    /**
     * @param dividend the dividend
     * @param divisor the divisor
     * @return the result
     */
    int divide(int dividend, int divisor) {
        long long result = 0;
        long long a = llabs(dividend);
        long long b = llabs(divisor);

        int shift = 31;
        while (shift >= 0) {
            if (a >= b << shift) {
                a -= b << shift;
                result += 1LL << shift;
            }
            --shift;
        }

        result = ((dividend ^ divisor) >> 31) ? -result : result;
        return min(result, static_cast<long long>(numeric_limits<int>::max()));
    }
};

// Time:  O(logn) = O(1)
// Space: O(1)
// a / b = exp^(ln(a) - ln(b))
class Solution3 {
public:
    /**
     * @param dividend the dividend
     * @param divisor the divisor
     * @return the result
     */
    int divide(int dividend, int divisor) {
        if (dividend == 0) { 
            return 0;
        }
        if (divisor == 0) {
            return numeric_limits<int>::max();
        }

        long long res = exp(log(fabs(dividend)) - log(fabs(divisor)));

        if ((dividend < 0) ^ (divisor < 0)) {
            res = -res;
        }
        if (res > numeric_limits<int>::max()) {
            res = numeric_limits<int>::max();
        }
        return res;
    }
};
