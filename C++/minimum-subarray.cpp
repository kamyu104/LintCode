// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        int min_sum = INT_MAX, sum = 0;
        for (auto& i : nums) {
            sum += i;
            min_sum = min(min_sum, sum);
            if (sum > 0) {
                sum = 0;
            }
        }
        return min_sum;
    }
};
