// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            while (left <= right && nums[left] % 2 == 1) {
                ++left;
            } 
            while (left <= right && nums[right] % 2 == 0) {
                --right;
            }
            if (left < right) {
               swap(nums[left++], nums[right--]);
            }
        }
    }
};
