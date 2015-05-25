// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            while (left <= right && nums[left] < k) {
                ++left;
            } 
            while (left <= right && nums[right] >= k) {
                --right;
            }
            if (left <= right) {
               swap(nums[left++], nums[right--]);
            }
        }
        
        return left;
    }
};

class Solution2 {
public:
    int partitionArray(vector<int> &nums, int k) {
        int left = 0;
        int right = nums.size();
        
        while (left < right) {
            if (nums[left] < k) { // Increase left boundary.
                ++left;
            } else { // Put every element > k to the right.
                swap(nums[left], nums[--right]);
            }
        }
        
        return left;
    }
};
