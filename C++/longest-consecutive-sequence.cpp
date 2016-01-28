// Time:  O(n)
// Space: O(n)

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    int longestConsecutive(vector<int> &num) {
        // unprocessed_entries records the existence of each entry in num.
        unordered_set<int> unprocessed_entries;
        for (const auto& a : num) {
            unprocessed_entries.emplace(a);
        }

        int max_interval_size = 0;
        while (!unprocessed_entries.empty()) {
            int a = *unprocessed_entries.begin();
            unprocessed_entries.erase(a);

            // Finds the lower bound of the largest range containing a.
            int lower_bound = a - 1;
            while (unprocessed_entries.count(lower_bound)) {
                unprocessed_entries.erase(lower_bound);
                --lower_bound;
            }

            // Finds the upper bound of the largest range containing a.
            int upper_bound = a + 1;
            while (unprocessed_entries.count(upper_bound)) {
                unprocessed_entries.erase(upper_bound);
                ++upper_bound;
            }
            max_interval_size =
            max(max_interval_size, upper_bound - lower_bound - 1);
        }
        return max_interval_size;
    }
};
