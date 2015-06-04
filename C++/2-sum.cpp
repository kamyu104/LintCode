// Time:  O(n)
// Space: O(n)

class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); ++i) {
            // Check if "target - nums[i]" exists or not
            if (hash.find(target - nums[i]) != hash.end()) {
                return {hash[target - nums[i]] + 1, i + 1};
            }
            hash[nums[i]] = i;
        }

        return {};
    }
};

