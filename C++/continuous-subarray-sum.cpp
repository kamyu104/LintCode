// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        if (A.empty()) {
            return {-1, -1};
        }

        int curr_sum = A[0];
        int max_sum = curr_sum;
        vector<int> max_i_j{0, 0};
        for (int i = 0, j = 1; j < A.size(); ++j) {
            if (curr_sum < 0) {
                i = j;
                curr_sum = 0;
            }

            curr_sum += A[j];
            if (curr_sum > max_sum) {
                max_sum = curr_sum;
                max_i_j[0] = i, max_i_j[1] = j;
            }
        }

        return max_i_j;
    }
};
