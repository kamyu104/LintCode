// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        int global_max = INT_MIN, local_max = 1, local_min = 1;

        for (const auto& n : nums) {
            int cur_max = local_max * n;
            int cur_min = local_min * n;
            local_max = max(n, max(cur_max, cur_min));
            local_min = min(n, min(cur_max, cur_min));
            global_max = max(global_max, local_max);
        }

        return global_max;
    }
};
