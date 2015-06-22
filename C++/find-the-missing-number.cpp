// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        int missing_num = 0;
        // xor all nums <= N.
        for (int num = 0; num <= nums.size(); ++num) {
            missing_num ^= num;
        }
        // Delete num in nums.
        for (const auto& num : nums) {
            missing_num ^= num;
        }
        // The remaining num would be missing num.
        return missing_num;
    }
};
