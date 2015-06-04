// Time:  O(k * n^k)
// Space: O(k)

class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> ans;
        CombinationsHelper(n, k, 1, &ans, &result);
        return result;
    }

    void CombinationsHelper(int n, int k,  int start, vector<int>* ans,
                            vector<vector<int>>* result) {
        if (ans->size() == k) {
            result->emplace_back(*ans);
            return;
        }

        for (int i = start; i <= n && k - ans->size() <= n - i + 1; ++i) {
            ans->emplace_back(i);
            CombinationsHelper(n, k, i + 1, ans, result);
            ans->pop_back();
        }
    }
};
