// Time:  O(n * 2^n)
// Space: O(1)

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        const int size = nums.size();
        const int set_size = 1 << size;
        vector<vector<int>> ans;
        vector<int> v;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < set_size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (i & (1 << j)) {
                    v.emplace_back(nums[j]);
                }
            }
            ans.emplace_back(v);
            v.clear();
        }

        return ans;
    }
};

// Time:  O(n * 2^n)
// Space: O(1)
class Solution2 {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
        vector<vector<int>> result(1);
        for (size_t i = 0; i < nums.size(); ++i) {
            const size_t size = result.size();
            for (size_t j = 0; j < size; ++j) {
                result.emplace_back(result[j]);
                result.back().emplace_back(nums[i]);
            }
        }
        return result;
    }
};
