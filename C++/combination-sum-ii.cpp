// Time:  O(k * C(n, k)), k is max length of combination
// Space: O(k)

class Solution {
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    vector<vector<int>> combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int>> ans;
        vector<int> v;
        combinationSum2Helper(num, target, 0, v, ans);
        return ans;
    }

private:
    void combinationSum2Helper(vector<int>& num, int gap, int begin,
                               vector<int>& v,vector<vector<int>> &ans) {
        if (gap == 0) {
            ans.emplace_back(v);
            return;
        }

        for (size_t i = begin; i < num.size() && num[i] <= gap; ++i) {
            if ( i == begin || num[i] != num[i - 1]) {  // Skip duplicates.
                // Each same element could be chosen only once
                // with the same previous nums.
                v.emplace_back(num[i]);
                combinationSum2Helper(num, gap - num[i], i + 1, v, ans);
                v.pop_back();
            }
        }
    }
};
