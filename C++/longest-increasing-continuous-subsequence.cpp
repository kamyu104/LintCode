// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        int max_inc_len = 0, cur_inc_len = 0;
        int max_dec_len = 0, cur_dec_len = 0;

        for (int i = 0; i < A.size(); ++i) {
            if (i == 0 || A[i] == A[i - 1]) {
                max_inc_len = max(max_inc_len, ++cur_inc_len);
                max_dec_len = max(max_dec_len, ++cur_dec_len);
            } else if (A[i] > A[i - 1]) {
                max_inc_len = max(max_inc_len, ++cur_inc_len);
                cur_dec_len = 1;
            } else if (A[i] < A[i - 1]) {
                max_dec_len = max(max_dec_len, ++cur_dec_len);
                cur_inc_len = 1;
            }
        }

        return max(max_inc_len, max_dec_len);
    }
};
