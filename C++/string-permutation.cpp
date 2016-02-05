// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param A a string
     * @param B a string
     * @return a boolean
     */
    bool stringPermutation(string& A, string& B) {
        if (A.length() != B.length()) {
            return false;
        }
        unordered_map<char, int> words;
        for (const auto& c : A) {
            ++words[c];
        }
        for (const auto& c : B) {
            if (words[c]) {
                --words[c];
            } else {
                return false;
            }
        }
        return true;
    }
};
