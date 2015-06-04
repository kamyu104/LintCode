// Time:  O(n)
// Space: O(n)

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: the maximum difference
     */
    int maximumGap(vector<int> nums) {
        if (nums.size() < 2) {
            return 0;
        }

        // Init bucket.
        int max_val = *max_element(nums.cbegin(), nums.cend());
        int min_val = *min_element(nums.cbegin(), nums.cend());
        int gap = max(1, static_cast<int>((max_val - min_val) /
                                          (nums.size() - 1)));
        map<int, array<int, 2>> bucket;
        typedef enum {MIN, MAX} ValueType;

        // Find the bucket where the n should be put.
        for (const auto& n : nums) {
            // min_val / max_val is in the first / last bucket.
            if (n == max_val || n == min_val) {
                continue ;    
            }
            int i = (n - min_val) / gap;
            bucket[i][MIN] = min(!bucket[i][MIN] ? INT_MAX : 
                                                   bucket[i][MIN], n);
            bucket[i][MAX] = max(!bucket[i][MAX] ? INT_MIN :
                                                   bucket[i][MAX], n);
        }

        // Count each bucket gap between the first and the last bucket.
        int max_gap = 0, pre_bucket_max = min_val;
        for (auto& kvp : bucket) {
            max_gap = max(max_gap, kvp.second[MIN] - pre_bucket_max);
            pre_bucket_max = (kvp.second)[MAX];
        }
        // Count the last bucket.
        max_gap = max(max_gap, max_val - pre_bucket_max);

        return max_gap;
    }
};
