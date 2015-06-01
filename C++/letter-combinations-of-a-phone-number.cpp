// Time:  O(n)
// Space: O(n)

// Iterative solution.
class Solution {
public:
    /**
     * @param digits A digital string
     * @return all posible letter combinations
     */
    vector<string> letterCombinations(string& digits) {
        if (digits.empty()) {
            return {};
        }
        
        vector<string> result = {""};
        vector<string> lookup = {"", "", "abc", "def", "ghi", "jkl", "mno", \
                                 "pqrs", "tuv", "wxyz"};
        
        for (int i = digits.size() - 1; i >= 0; --i) {
            const string& choices = lookup[digits[i] - '0'];
            const int n = result.size(), m = choices.length();
            for (int j = n; j < m * n; ++j) {
                result.emplace_back(result[j % n]);
            }
            for (int j = 0; j < m * n; ++j) {
                result[j].insert(result[j].end(), choices[j / n]);
            }
        }
        for (auto& s : result) {
            reverse(s.begin(), s.end());
        }
        
        return result;
    }
};
