// Time:  O(n)
// Space: O(1)

// Sliding window solution.
class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        int start = -1, sum = 0, min_size = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            while (sum >= s) {
                min_size = min(min_size, i - start);
                sum -= nums[++start];
            }
        }
        if (min_size == INT_MAX) {
            return 0;
        }
        return min_size;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// Binary search solution.
class Solution2 {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        int min_size = INT_MAX;
        vector<int> sum_from_start(nums.size());
        partial_sum(nums.begin(), nums.end(), sum_from_start.begin());
        for (int i = 0; i < nums.size(); ++i) {
            const auto& end_it = lower_bound(sum_from_start.begin() + i,
                                             sum_from_start.end(),
                                             sum_from_start[i] - nums[i] + s);
            int end = static_cast<int>(end_it - sum_from_start.begin());
            if (end_it != sum_from_start.end()) {
                min_size = min(min_size, end - i + 1);
            }
        }
        if (min_size == INT_MAX) {
            return 0;
        }
        return min_size;
    }
};
