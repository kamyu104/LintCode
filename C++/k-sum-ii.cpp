// Time:  O(k * C(n, k))
// Space: O(k)

class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer
     */
    vector<vector<int>> kSumII(vector<int> A, int k, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(A, k, 0, target, curr, ans);
        return ans;
    }

    void helper(vector<int> A, int k, int start, int target, vector<int>& curr, vector<vector<int>> & ans) {
        if (k < 0 || target < 0) {
            return;
        }

        if (k == 0 && target == 0) {
            ans.emplace_back(curr);
            return;
        }

        for (int i = start; i <= A.size() - k; i++) {
            curr.emplace_back(A[i]);
            helper(A, k - 1, i + 1, target - A[i], curr, ans);
            curr.pop_back();
        }
    }
};

