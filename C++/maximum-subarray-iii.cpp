// Time:  O(k * n)
// Space: O(k * n)

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxSubArray(vector<int> nums, int k) {
        const int n = nums.size();
        // local_max[x][y] means the max sum in range [0, x - 1] include nums[x-1]
        // with y non-overlapping subarrays.
        vector<vector<int>> local_max(n + 1,
                            vector<int>(k + 1, numeric_limits<int>::min()));
        // global_max[x][y] means the max sum in range [0, x - 1]
        // with y non-overlapping subarrays.
        vector<vector<int>> global_max(n + 1,
                            vector<int>(k + 1, numeric_limits<int>::min()));

        for (int i = 0; i <= n; ++i) {
            global_max[i][0] = 0;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(i, k); ++j) {
                local_max[i][j] = max(local_max[i - 1][j],
                                      global_max[i - 1][j - 1]) + nums[i - 1];
                if (j == i) {
                    global_max[i][j] = local_max[i][j];
                } else {
                    global_max[i][j] = max(global_max[i - 1][j],
                                           local_max[i][j]);
                }
            }
        }

        return global_max[n][k];
    }
};

// Time:  O(k * n^2)
// Space: O(k * n)
class Solution2 {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxSubArray(vector<int> nums, int k) {
        const int n = nums.size();

        // sums[x][y] means the max sum in range [0, x - 1] with y non-overlapping subarrays
        vector<vector<int>> sums(n + 1, vector<int>(k + 1, INT_MIN));

        for (int i = 0; i <= n; ++i) {
            sums[i][0] = 0;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(i, k); ++j) {
                sums[i][j] = sums[i - 1][j];
                int max_sum_from_p = 0;
                for (int p = i; p > j - 1; --p) {
                    max_sum_from_p = max(0, max_sum_from_p) + nums[p - 1];
                    // max sum in range[0, i - 1] with j subarrays equals to
                    // max sum in max(range [0, p - 2] with j - 1 subarrys plus
                    // max sum of the subarray which starts from p - 1 
                    sums[i][j] = max(sums[i][j], sums[p - 1][j - 1] + max_sum_from_p);
                }
            }
        }

        return sums[n][k];
    }
};

// Time:  O(k * n^2)
// Space: O(k * n)
class Solution3 {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxSubArray(vector<int> nums, int k) {
        const int n = nums.size();

        // sums[x][y] means the max sum in range [0, x - 1] with y non-overlapping subarrays
        vector<vector<int>> sums(n + 1, vector<int>(k + 1, INT_MIN));

        for (int i = 0; i <= n; ++i) {
            sums[i][0] = 0;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(i, k); ++j) {
                sums[i][j] = sums[i - 1][j];
                int sum = 0, max_sum = INT_MIN;
                for (int p = i; p > j - 1; --p) {
                    sum += nums[p - 1];
                    max_sum = max(max_sum, sum);
                    sum = max(0, sum);
                    // max sum in range[0, i - 1] with j subarrays equals to
                    // max sum in max(range [0, p - 2] with j - 1 subarrys plus
                    // max sum in range [p - 1, i - 1] with 1 subarray 
                    sums[i][j] = max(sums[i][j], sums[p - 1][j - 1] + max_sum);
                }
            }
        }

        return sums[n][k];
    }
};
