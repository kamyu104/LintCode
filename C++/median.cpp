// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        auto target = nums.begin() + nums.size() / 2;
        nth_element(nums.begin(), target, nums.end());
        if (nums.size() % 2 == 1) {  // nums has odd number of elements.
            return *target;
        } else {  // nums has even number of elements.
            int x = *target;
            nth_element(nums.begin(), target - 1, nums.end());
            return *(target - 1);
        }
    }
};

