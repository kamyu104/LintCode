// Time:  O(n * 2^n)
// Space: O(n)

class Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> partition;
        PalindromePartitioningHelper(s, 0, &partition, &result);
        return result;
    }

    void PalindromePartitioningHelper(const string& s, size_t begin,
                                      vector<string>* partition,
                                      vector<vector<string>>* result) {
        if (begin == s.size()) {
            result->emplace_back(*partition);
            return;
        }

        for (size_t i = begin + 1; i <= s.size(); ++i) {
            string prefix = s.substr(begin, i - begin);
            if (IsPalindrome(prefix)) {
                partition->emplace_back(prefix);
                PalindromePartitioningHelper(s, i, partition, result);
                partition->pop_back();
            }
        }
    }

    bool IsPalindrome(const string& s) {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
};
