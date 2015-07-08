// Time:  O(k * n^k), k is max length of combination
// Space: O(k)

class Solution {
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    vector<vector<int>> combinationSum(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int>> ans;
        vector<int> v;
        combinationSumHelper(num, target, 0, v, ans);
        return ans;
    }

private:
    void combinationSumHelper(vector<int>& num, int gap, int begin,
                              vector<int>& v,vector<vector<int>> &ans) {
        if (gap == 0) {
            ans.emplace_back(v);
            return;
        }

        for (size_t i = begin; i < num.size() && num[i] <= gap; ++i) {
            v.emplace_back(num[i]);
            combinationSumHelper(num, gap - num[i], i, v, ans);
            v.pop_back();
        }
    }
};
