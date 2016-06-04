// Time:  O(m + n)
// Space: O(min(m, n))

// Hash solution.
class Solution {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersection(nums2, nums1);
        }

        unordered_map<int, int> lookup;
        for (const auto& i : nums1) {
            ++lookup[i];
        }

        vector<int> result;
        for (const auto& i : nums2) {
            if (lookup[i] > 0) {
                result.emplace_back(i);
                --lookup[i];
            }
        }

        return result;
    }
};


// Time:  O(max(m, n) * log(max(m, n)))
// Space: O(1)
// Binary search solution.
class Solution2 {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersection(nums2, nums1);
        }

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> result;
        auto it = nums2.cbegin();
        for (const auto& i : nums1) {
            it = lower_bound(it, nums2.cend(), i);
            if (it != nums2.end() && *it == i) {
                result.emplace_back(*it++);
            }
        }
        
        return result;
    }
};


// Time:  O(max(m, n) * log(max(m, n)))
// Space: O(1)
// Two pointers solution.
class Solution3 {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        auto it1 = nums1.cbegin(), it2 = nums2.cbegin();
        while (it1 != nums1.cend() && it2 != nums2.cend()) {
            if (*it1 < *it2) {
                ++it1;
            } else if (*it1 > *it2) {
                ++it2;
            } else {
                result.emplace_back(*it1);
                ++it1, ++it2;
            }
        }
        return result;
    }
};
