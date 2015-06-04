// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }

        return robRange(nums, 0, nums.size());

    }

    long long robRange(const vector<int>& nums, const int start, const int end) {
        long long num_i = nums[start], num_i_1 = 0, num_i_2 = 0;
        for (int i = start + 1; i < end; ++i) {
            num_i_2 = num_i_1;
            num_i_1 = num_i;
            num_i = max(nums[i] + num_i_2, num_i_1);
        }
        return num_i;
    }
};
