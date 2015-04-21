// Time:  O(k * n^2)
// Space: O(k * n^2)

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxSubArray(vector<int> nums, int k) {
        int n = nums.size();
        
        vector<vector<int>> sums(n + 1, vector<int>(k + 1, INT_MIN));
        
        for(int i = 0; i <= n; ++i) {
            sums[i][0] = 0;
        }
        
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= min(i, k); ++j) {
                sums[i][j] = sums[i - 1][j];
                int sum_p_i = 0;
                for(int p = i; p > j - 1; --p) {
                    sum_p_i = max(0, sum_p_i) + nums[p - 1];
                    sums[i][j] = max(sums[i][j], sums[p - 1][j - 1] + sum_p_i);
                }
            }
        }
        
        return sums[n][k];
    }
};
