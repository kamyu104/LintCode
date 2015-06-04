// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        int left = 0;
        int right = 1;

        while (right < nums.size()) {
            if (nums[left] != nums[right]) {
                ++left;
                nums[left] = nums[right];
            }
            ++right;
        }

        return left + 1;
    }
};
