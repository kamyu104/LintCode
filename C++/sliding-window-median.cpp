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
        // min_heap stores the larger half seen so far.
        multiset<int, less<int>> min_bst;
        // max_heap stores the smaller half seen so far.
        multiset<int, greater<int>> max_bst;
        
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k) {
                // Remove the element outside the window.
                if (max_bst.find(nums[i - k]) != max_bst.end()) {
                    max_bst.erase(max_bst.find(nums[i - k]));
                } else {
                    min_bst.erase(min_bst.find(nums[i - k]));
                }
            }
            
            // Balance smaller half and larger half.
            if (max_bst.empty() || nums[i] > *max_bst.begin()) {
                min_bst.insert(nums[i]);
                if (min_bst.size() > max_bst.size() + 1) {
                    max_bst.insert(*min_bst.begin());
                    min_bst.erase(min_bst.begin());
                }
            }
            else {
                max_bst.insert(nums[i]);
                if (max_bst.size() > min_bst.size()) {
                    min_bst.insert(*max_bst.begin());
                    max_bst.erase(max_bst.begin());
                }
            }
            
            // If window is full, get the median from 2 BST.
            if (i >= k - 1) {
                ans.emplace_back(min_bst.size() == max_bst.size() ?
                                 *max_bst.begin() : *min_bst.begin());
            }
        }
        
        return ans;
    }
};

