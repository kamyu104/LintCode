// Time:  O(nlogn)
// Space: O(n)

// Binary search solution with STL.
class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        vector<int> LIS;

        for (const auto& i : nums) {
            insert(&LIS, i);
        }

        return LIS.size();
    }

private:
    void insert(vector<int> *LIS, const int target) {
        // Find the first index "left" which satisfies LIS[left] > target
        auto it = upper_bound(LIS->begin(), LIS->end(), target);

        // If not found, append the target.
        if (it == LIS->end()) {
            LIS->emplace_back(target);
        } else {
            *it = target;
        }
    }
};

// Binary search solution.
class Solution2 {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        vector<int> LIS;

        for (const auto& i : nums) {
            insert(&LIS, i);
        }

        return LIS.size();
    }

private:
    void insert(vector<int> *LIS, const int target) {
        int left = 0, right = LIS->size() - 1;
        auto comp = [](int x, int target) { return x > target; };

        // Find the first index "left" which satisfies LIS[left] > target
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (comp((*LIS)[mid], target)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // If not found, append the target.
        if (left == LIS->size()) {
            LIS->emplace_back(target);
        } else {
            (*LIS)[left] = target;
        }
    }
};

