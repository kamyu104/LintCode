// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // min_bst stores the larger half seen so far.
        multiset<int, less<int>> min_bst;
        // max_bst stores the smaller half seen so far.
        multiset<int, greater<int>> max_bst;

        vector<int> ans;
        for (const auto& num : nums) {
            // Balance smaller half and larger half.
            if (max_bst.empty() || num > *max_bst.cbegin()) {
                min_bst.emplace(num);
                if (min_bst.size() > max_bst.size() + 1) {
                    max_bst.emplace(*min_bst.cbegin());
                    min_bst.erase(min_bst.cbegin());
                }
            } else {
                max_bst.emplace(num);
                if (max_bst.size() > min_bst.size()) {
                    min_bst.emplace(*max_bst.cbegin());
                    max_bst.erase(max_bst.cbegin());
                }
            }

            ans.emplace_back(min_bst.size() == max_bst.size() ?
                             *max_bst.cbegin() : *min_bst.cbegin());
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
        for (const auto& num : nums) {
            if (max_heap.empty() || num > max_heap.top()) {
                min_heap.emplace(num);
                if (min_heap.size() > max_heap.size() + 1) {
                    max_heap.emplace(min_heap.top());
                    min_heap.pop();
                }
            } else {
                max_heap.emplace(num);
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

