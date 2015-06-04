// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
     */
    void nextPermutation(vector<int> &nums) {
        int k = -1, l = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] < nums[i + 1]) {
                k = i;
            }
        }

        if (k >= 0) {
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] > nums[k]) {
                    l = i;
                }
            }
            swap(nums[k], nums[l]);
        }
        reverse(nums.begin() + k + 1, nums.end());
    }
};

class Solution2 {
public:
    /**
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
     */
    void nextPermutation(vector<int> &nums) {
        next_permutation(nums.begin(), nums.end());
    }
};
