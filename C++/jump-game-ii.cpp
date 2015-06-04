// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        int jump_count = 0;
        int reachable = 0;
        int curr_reachable = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (i > reachable) {
                return -1;
            }
            if (i > curr_reachable) {
                // current jumps are not enough,
                // jump one more step, which enlarges curr_reachable to reachable.
                curr_reachable = reachable;
                ++jump_count;
            }
            reachable = max(reachable, i + A[i]);
        }

        return jump_count;
    }
};


