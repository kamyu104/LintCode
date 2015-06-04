// Time:  O(n * 2^n)
// Space: O(1)

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int>> subsetsWithDup(const vector<int> &S) {
        vector<int> sorted_S(S);
        sort(sorted_S.begin(), sorted_S.end());
        vector<vector<int>> result(1);
        size_t previous_size = 0;
        for (size_t i = 0; i < sorted_S.size(); ++i) {
            const size_t size = result.size();
            for (size_t j = 0; j < size; ++j) {
                // only union non-duplicate element or new union set
                if (i == 0 || sorted_S[i] != sorted_S[i - 1] || j >= previous_size) {
                    result.emplace_back(result[j]);
                    result.back().emplace_back(sorted_S[i]);
                }
            }
            previous_size = size;
        }
        return result;
    }
};
