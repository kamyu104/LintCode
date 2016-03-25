// Time:  O(nlogw)
// Space: O(w)

#include <vector>
#include <set>

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
        // min_bst stores the larger half seen so far.
        multiset<int, less<int>> min_bst;
        // max_bst stores the smaller half seen so far.
        multiset<int, greater<int>> max_bst;

        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k) {
                // Remove the element outside the window.
                if (max_bst.find(nums[i - k]) != max_bst.cend()) {
                    max_bst.erase(max_bst.find(nums[i - k]));
                } else {
                    min_bst.erase(min_bst.find(nums[i - k]));
                }
            }

            // Balance smaller half and larger half.
            if (max_bst.empty() || nums[i] > *max_bst.cbegin()) {
                min_bst.emplace(nums[i]);
                if (min_bst.size() > max_bst.size() + 1) {
                    max_bst.emplace(*min_bst.cbegin());
                    min_bst.erase(min_bst.cbegin());
                }
            } else {
                max_bst.emplace(nums[i]);
                if (max_bst.size() > min_bst.size()) {
                    min_bst.emplace(*max_bst.cbegin());
                    max_bst.erase(max_bst.cbegin());
                }
            }

            // If window is full, get the median from 2 BST.
            if (i >= k - 1) {
                ans.emplace_back(min_bst.size() == max_bst.size() ?
                                 *max_bst.cbegin() : *min_bst.cbegin());
            }
        }

        return ans;
    }
};

