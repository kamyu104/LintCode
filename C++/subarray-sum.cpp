class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums) {
        unordered_map<int, int> table;
        table[0] = -1;
        for (int i = 0, sum = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (!table.emplace(sum, i).second) {  // Already exists.
                return {table[sum] + 1, i};
            }
        }
        return {};
    }
};
