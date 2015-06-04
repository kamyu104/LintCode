// Time:  O(n^2)
// Space: O(1)

class Solution {
public:
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> ans;
        const int target = 0;

        // Make nums in increasing order. Time: O(nlogn)
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; ++i) {
            // Skip duplicated.
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {  // Time: O(n) for each i.
                if (j - 1 > i  && nums[j] == nums[j - 1]) {  // Skip duplicated.
                    ++j;
                } else if (k + 1 < nums.size() && nums[k] == nums[k + 1]) {  // Skip duplicated.
                    --k;
                } else {
                    const auto sum = nums[i] + nums[j] + nums[k];

                    if (sum > target) {  // Should decrease sum.
                        --k;
                    } else if (sum < target) {  // Should increase sum.
                        ++j;
                    } else {
                        ans.emplace_back(vector<int>{nums[i], nums[j], nums[k]});
                        ++j;
                        --k;
                    }
                }
            }
        }

        return ans;
    }
};

