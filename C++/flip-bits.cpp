// Time:  O(logn) = O(32)
// Space: O(1)

class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        int cnt = 0;
        for (int c = a ^ b; c != 0; c &= c - 1) {
            ++cnt;
        }
        return cnt;
    }
};
