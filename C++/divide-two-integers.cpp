// Time:  O(logn)
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

// Time:  O(logn)
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
        long long result = 0, dvd = llabs(dividend), dvs = llabs(divisor);
        
        long long inc = dvs;
        long long multiplier = 1; 
        int i = 0;
        while (dvd >= inc) {
                inc <<= 1;
                multiplier <<= 1;
                ++i;
        }
        
        while (inc && i >= 0) {
                while (dvd >= inc) {
                    dvd -= inc;
                    result += multiplier;
                }
                inc >>= 1;
                multiplier >>= 1;
                --i;
        }
            
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
            return -result;
        } else {
            return min(result, static_cast<long long>(INT_MAX));
        }
    }
};

// Time:  O(1)
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
            return INT_MAX;
        }
        
        long long res = exp(log(fabs(dividend)) - log(fabs(divisor)));
        
        if ((dividend < 0) ^ (divisor < 0)) {
            res = -res;
        }
        if (res > INT_MAX) {
            res = INT_MAX;
        }
        return res;
    }
};
