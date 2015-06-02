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
        // Case for all elements are negative.
        const auto it = max_element(A.cbegin(), A.cend());
        if (it != A.cend() && *it < 0) {
            return {distance(A.cbegin(), it), distance(A.cbegin(), it)};
        }
        
        int curr_sum = 0;
        int max_sum = INT_MIN;
        int i = 0, j = 0;
        vector<int> max_i_j{-1, -1};
        while (j < A.size()) {
            curr_sum += A[j];
            if (curr_sum >= 0) {
                if (curr_sum > max_sum) {
                    max_sum = curr_sum;
                    max_i_j[0] = i, max_i_j[1] = j;
                }
            } else {
                curr_sum = 0;
                i = j + 1;
            }
            ++j;
        }
        
        return max_i_j;
    }
};
