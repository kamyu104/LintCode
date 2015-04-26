// Time:  O(n)
// Space: O(n)

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        unordered_map<int, int> table;
        
        for (int i = 0, sum = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum == 0) {
                return vector<int>{0, i};
            }
            else if (table.find(sum) != table.end()) {
                return vector<int>{table[sum] + 1, i};
            } else {
                table[sum] = i;
            }
        }
    }
};
