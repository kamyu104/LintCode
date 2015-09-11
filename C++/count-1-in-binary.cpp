// Time:  O(logn) = O(32)
// Space: O(1)

class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        int count = 0;
        for (; num; num &= num - 1) {
            ++count;
        }
        return count;
    }
};
