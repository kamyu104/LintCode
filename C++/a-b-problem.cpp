// Time:  O(logn) = O(32)
// Space: O(1)

class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        while (b != 0) {
            int carry = a & b;
            a ^= b;
            b = carry << 1;
        }
        return a;
    }
};

class Solution2 {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        if (b == 0) {
            return a;
        }
        return aplusb(a ^ b, (a & b) << 1);
    }
};
