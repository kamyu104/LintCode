// Time:  O(nlogn)
// Space: O(n)

// Binary search solution.
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
        partial_sum(A.cbegin(), A.cend(), sum_from_start.begin() + 1);

        int result = 0;
        for (int j = 0; j < A.size(); ++j) {
            const auto left = lower_bound(sum_from_start.cbegin(),
                                          sum_from_start.cbegin() + j + 1,
                                          sum_from_start[j + 1] - end);
            const auto right = upper_bound(sum_from_start.cbegin(),
                                           sum_from_start.cbegin() + j + 1,
                                           sum_from_start[j + 1] - start);
            result += (right - sum_from_start.cbegin()) - 
                      (left - sum_from_start.cbegin());
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
        partial_sum(A.cbegin(), A.cend(), sum_from_start.begin() + 1);

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
