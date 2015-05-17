// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    bool wordSegmentation(string s, unordered_set<string> &dict) {
        const int n = s.length();
        if (n < 1) {
            return true;
        }
        
        // Filter out impossible string which alphabet set is not covered by dict.
        unordered_set<char> chrs;
        for (const auto& word : dict) {
            for(const auto& c : word) {
                chrs.insert(c);
            }
        } 
        for(const auto& c : s) {
            if (chrs.find(c) == chrs.end())
                return false;
        }
        
        // DP
        vector<bool> canBreak(n, false);
        for (int i = 0; i < n; ++i) {
            for (int j = i; j >= 0; --j) {
                if ((j == 0 || canBreak[j-1]) && dict.count(s.substr(j, i - j + 1))) {
                    canBreak[i] = true;
                    break;
                }
            }
        }
        
        return canBreak[n - 1];
    }
};
