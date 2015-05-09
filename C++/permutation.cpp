// Time:  O(n * n!)
// Space: O(n)

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        if (nums.empty()) {
            return {};
        }
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        do {
            result.emplace_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return result;
    }
};

