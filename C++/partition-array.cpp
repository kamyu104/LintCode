// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        for (int left = 0, right = nums.size() - 1; left < right;) {
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


class Solution2 {
public:
    int partitionArray(vector<int> &nums, int k) {
        int left = 0;
        int right = nums.size();

        while (left < right) {
            if (nums[left] < k) {  // Increase left boundary.
                ++left;
            } else {  // Put every element > k to the right.
                swap(nums[left], nums[--right]);
            }
        }

        return left;
    }
};
