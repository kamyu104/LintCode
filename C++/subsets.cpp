// Time:  O(n * 2^n)
// Space: O(1)

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
        const int size = nums.size();
        const int set_size = 1 << size;
        vector<vector<int> > ans;
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
