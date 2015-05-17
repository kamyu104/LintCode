// Time:  O(n^2)
// Space: O(1)

class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        int ans = INT_MAX;
        int min_diff = INT_MAX;
        
        // Make nums in increasing order. Time: O(nlogn)
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2; ++i) {
            // Skip duplicated.
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;
            
            while (j < k) { // Time: O(n) for each i.
                const auto& sum = nums[i] + nums[j] + nums[k];
                
                if (sum > target) { // Should decrease sum.
                    --k;
                } else if (sum < target) { // Should increase sum.
                    ++j;
                } else {
                    return target;
                }
                
                if (abs(sum - target) < min_diff) {
                    min_diff = abs(sum - target);
                    ans = sum;
                }
            }
        }
        
        return ans;
    }
};


