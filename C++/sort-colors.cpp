// Time:  O(n)
// Space: O(1)

class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2
     * @return: nothing
     */
    void sortColors(vector<int> &nums) {
        int i = 0;
        int last_zero = -1;
        int first_two = nums.size();

        while (i < first_two) {
            if (nums[i] == 2) {
                swap(nums[i], nums[--first_two]);
            } else if (nums[i] == 0) {
                swap(nums[i++], nums[++last_zero]);
            } else { // case 1
                ++i;
            }
        }
    }
};
