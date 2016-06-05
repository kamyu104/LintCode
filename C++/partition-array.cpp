// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            if (nums[left] < k) {
                ++left;
            } else if (nums[right] >= k) {
                --right;
            } else {
               swap(nums[left++], nums[right--]);
            }
        }
        
        return left;
    }
};
