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
                    max_sum_from_p = max(0, max_sum_from_p) + nums[p - 1];
                    sums[i][j] = max(sums[i][j], sums[p - 1][j - 1] + max_sum_from_p);
                }
            }
        }
        
        return sums[n][k];
    }
};

// Time:  O(k * n^2)
// Space: O(k * n^2)

class Solution2 {
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
                int sum = 0, max_sum = INT_MIN;
                for(int p = i; p > j - 1; --p) {
                    sum += nums[p - 1];
                    max_sum = max(max_sum, sum);
                    sum = max(0, sum);
                    sums[i][j] = max(sums[i][j], sums[p - 1][j - 1] + max_sum);
                }
            }
        }
        
        return sums[n][k];
    }
};
