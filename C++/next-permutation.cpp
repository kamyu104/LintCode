// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermuation(vector<int> &nums) {
        int k = -1, l = 0;

        // Find the last index k before the decreasing sequence.
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] < nums[i + 1]) {
                k = i;
            }
        }

        if (k >= 0) {
            // Find the smallest number which is larger than the value of the index k,
            // and swap the values.
            for (int i = k + 1; i < nums.size(); ++i) {
                if (nums[i] > nums[k]) {
                    l = i;
                }
            }
            swap(nums[k], nums[l]);
        }

        // Reverse the sequence after the index k.
        reverse(nums.begin() + k + 1, nums.end());

        return nums;
    }
};

class Solution2 {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermuation(vector<int> &nums) {
        next_permutation(nums.begin(), nums.end());
        return nums;
    }
};
