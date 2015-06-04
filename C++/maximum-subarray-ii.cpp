// Time:  O(n)
// Space: O(n)

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        int n = nums.size();
        vector<int> max_LR(n);
        vector<int> max_RL(n);

        // Compute the max sum of subarray from left to right.
        int max_LR_sum = INT_MIN, LR_sum = 0;
        for (int i = 0; i < n; ++i) {
            LR_sum += nums[i];
            max_LR_sum = max(max_LR_sum, LR_sum);
            max_LR[i] = max_LR_sum;
            LR_sum = max(LR_sum, 0);
        }

        // Compute the max sum of subarray from right to left.
        int max_RL_sum = INT_MIN, RL_sum = 0;
        for (int i = n - 1; i >= 0; --i) {
            RL_sum += nums[i];
            max_RL_sum = max(max_RL_sum, RL_sum);
            max_RL[i] = max_RL_sum;
            RL_sum = max(RL_sum, 0);
        }

        // Compute the max sum of two non-overlapping subarrays.
        int max_sum = INT_MIN;
        for (int i = 0; i < n - 1; ++i) {
            max_sum = max(max_sum, max_LR[i] + max_RL[i+1]);
        }

        return max_sum;
    }
};



