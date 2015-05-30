// Time:  O(nlogn)
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
        vector<int> sum_from_start(A.size() + 1);
        partial_sum(A.begin(), A.end(), sum_from_start.begin() + 1);
        
        int result = 0;
        for (int i = 0, j = 0; j < A.size(); ++j) {
            if (sum_from_start[j + 1] >= start) {
                auto l = lower_bound(sum_from_start.begin(), sum_from_start.begin() + j + 1,
                                     sum_from_start[j + 1] - end);
                auto r = upper_bound(sum_from_start.begin(), sum_from_start.begin() + j + 1,
                                     sum_from_start[j + 1] - start);
                if (l != sum_from_start.begin() + j + 1) {
                    result += (r - sum_from_start.begin()) - (l - sum_from_start.begin());
                }
            }
        }
        
        return result;
    }
};

// Time:  O(n^2)
// Space: O(n)
class Solution2 {
public:
    /**
     * @param A an integer array
     * @param start an integer
     * @param end an integer
     * @return the number of possible answer
     */
    int subarraySumII(vector<int>& A, int start, int end) {
        // sum_from_start[i] denotes sum for 0 ~ i - 1.
        vector<int> sum_from_start(A.size() + 1);
        partial_sum(A.begin(), A.end(), sum_from_start.begin() + 1);
        
        int result = 0;
        for (int i = 0, j = 0; j < A.size(); ++j) {
            int k = i;
            while (k <= j) {
                if (sum_from_start[j + 1] - sum_from_start[k] >= start &&
                    sum_from_start[j + 1] - sum_from_start[k] <= end) {
                    ++result;
                }
                ++k;
            }
        }
        
        return result;
    }
};
