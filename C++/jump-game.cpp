// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        int reachable = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (i > reachable) {
                return false;
            }
            reachable = max(reachable, i + A[i]);
        }

        return true;
    }
};

