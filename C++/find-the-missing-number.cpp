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

// Time:  O(n)
// Space: O(n)
class Solution2 {
public:
    int findMissing(vector<int> &nums) {
        vector<int> expected(nums.size()); 
        iota(expected.begin(), expected.end(), 1);  // Costs extra space O(n)
        return accumulate(nums.cbegin(), nums.cend(), 0, bit_xor<int>()) ^
               accumulate(expected.cbegin(), expected.cend(), 0, bit_xor<int>());
    }
};
