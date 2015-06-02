// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        int max_sum = INT_MIN, sum = 0;
        for (const auto& i : nums) {
            sum += i;
            max_sum = max(max_sum, sum);
            sum = max(sum, 0);
        }
        return max_sum;
    }
};

