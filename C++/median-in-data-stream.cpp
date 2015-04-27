// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // min_heap stores the larger half seen so far.
        multiset<int, less<int>> min_bst;
        // max_heap stores the smaller half seen so far.
        multiset<int, greater<int>> max_bst;
        
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            
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
            
            ans.emplace_back(min_bst.size() == max_bst.size() ?
                             *max_bst.begin() : *min_bst.begin());
        }
        
        return ans;
    }
};


class Solution2 {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // min_heap stores the larger half seen so far.
        priority_queue<int, vector<int>, greater<int>> min_heap;
        // max_heap stores the smaller half seen so far.
        priority_queue<int, vector<int>, less<int>> max_heap;
        
        vector<int> ans;
        int x;
        for (auto& x : nums) {
            if (max_heap.empty() || x > max_heap.top()) {
                min_heap.emplace(x);
                if (min_heap.size() > max_heap.size() + 1) {
                    max_heap.emplace(min_heap.top());
                    min_heap.pop();
                }
            }
            else {
                max_heap.emplace(x);
                if (max_heap.size() > min_heap.size()) {
                    min_heap.emplace(max_heap.top());
                    max_heap.pop();
                }
            }
            
            ans.emplace_back(min_heap.size() == max_heap.size() ?
                             max_heap.top() : min_heap.top());
        }
        
        return ans;
    }
};

