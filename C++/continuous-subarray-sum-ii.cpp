// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySumII(vector<int>& A) {
        vector<int> result{-1, -1};
        int max_sum = numeric_limits<int>::min();
        int total = 0;

        // Non-circular subarray.
        int sum = 0;
        int start = 0, end = 0;
        for (int i = 0; i < A.size(); ++i) {
            total += A[i];
            if (sum < 0) {
                sum = A[i];
                start = end = i;
            } else {
                sum += A[i];
                end = i;
            }
            if (sum >= max_sum) {
                max_sum = sum;
                result[0] = start;
                result[1] = end;
            }
        }

        // Circular subarray.
        sum = 0;
        start = 0, end = -1;
        for (int i = 0; i < A.size(); ++i) {
            if (sum > 0) {
                sum = A[i];
                start = end = i;
            } else {
                sum += A[i];
                end = i;
            }
            if (total - sum > max_sum && !(start == 0 && end == A.size() - 1)) {
                max_sum = total - sum;
                result[0] = (end + 1) % A.size();
                result[1] = (start - 1) % A.size();
            }
        }

        return result;
    }
};
