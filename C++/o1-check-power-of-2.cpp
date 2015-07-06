// Time:  O(1)
// Space: O(1)

class Solution {
public:
    /*
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};
