// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * param A: A string
     * param offset: Rotate string with offset.
     * return: Rotated string.
     */
    string rotateString(string A, int offset) {
        if (!A.empty()) {
            offset %= A.length();
            reverse(A.begin(), A.begin() + A.length() - offset);
            reverse(A.begin() + A.length() - offset, A.end());
            reverse(A.begin(), A.end());
        }
        return A;
    }
};
