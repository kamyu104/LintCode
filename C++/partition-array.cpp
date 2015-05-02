// Time:  O(n)
// Space: O(1)

class Solution {
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
