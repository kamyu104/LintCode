// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    /**
     * @param A an integer array
     * @param start an integer
     * @param end an integer
     * @return the number of possible answer
     */
    int subarraySumII(vector<int>& A, int start, int end) {
        // sum_from_start[i] denotes sum for 0 ~ i - 1.
        vector<int> sum_from_start(A.size());
        partial_sum(A.begin(), A.end(), sum_from_start.begin());
        
        int result = 0;
        for (int i = 0, j = 0; j < A.size(); ++j) {
            int k = i;
            while (k <= j) {
                if (sum_from_start[j] - sum_from_start[k] + A[k] >= start &&
                    sum_from_start[j] - sum_from_start[k] + A[k] <= end) {
                    ++result;
                }
                ++k;
            }
        }
        
        return result;
    }
};
