// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        for (int left = 0, right = nums.size() - 1; left <= right;) {
            if (nums[left] % 2 == 1) {
                ++left;
            } else if  (nums[right] % 2 == 0) {
                --right;
            } else {
               swap(nums[left++], nums[right--]);
            }
        }
    }
};
