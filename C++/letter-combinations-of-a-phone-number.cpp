// Time:  O(n * 4^n)
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
        vector<string> lookup = {"", "", "abc", "def",
                                 "ghi", "jkl", "mno",
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

// Time:  O(n * 4^n)
// Space: O(n)
// Recursion solution.
class Solution2 {
public:
    /**
     * @param digits A digital string
     * @return all posible letter combinations
     */
    vector<string> letterCombinations(string& digits) {
        if (digits.empty()) {
            return {};
        }

        vector<string> result = {};
        vector<string> lookup = {"", "", "abc", "def",
                                 "ghi", "jkl", "mno",
                                 "pqrs", "tuv", "wxyz"};
        string combination;
        int len = 0;
        letterCombinationsRecu(digits, lookup, &combination, &len, &result);
        return result;
    }

    void letterCombinationsRecu(const string& digits, vector<string>& lookup,
                                string *combination,
                                int *len, vector<string> *result) {
       if (*len == digits.size()) {
            result->emplace_back(*combination);
        } else {
            for (const auto& c : lookup[digits[*len] - '0']) {
                combination->insert(combination->end(), c), ++(*len);
                letterCombinationsRecu(digits, lookup, combination, len, result);
                combination->pop_back(), --(*len);
            }
        }
    }
};
