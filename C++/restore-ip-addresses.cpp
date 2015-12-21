// Time:  O(n^m) = O(3^4)
// Space: O(n * m) = O(3 * 4)

class Solution {
public:
    /**
     * @param s the IP string
     * @return All possible valid IP addresses
     */
    vector<string> restoreIpAddresses(string& s) {
        vector<string> result;
        string cur;
        restoreIpAddressesHelper(s, 0, 0, &cur, &result);
        return result;
    }

    void restoreIpAddressesHelper(const string& s,
                                  int start, int dots,
                                  string *cur,
                                  vector<string> *result) {
        // Pruning to improve performance.
        if (((4 - dots) * 3 < s.length() - start) ||
            ((4 - dots) > s.length() - start)) {
            return;
        }

        if (start == s.length() && dots == 4) {
            result->emplace_back(cur->begin(), prev(cur->end()));
        } else {
            for (int i = start; i < start + 3; ++i) {
                string tmp = s.substr(start, i - start + 1);
                if (i < s.length() && isValid(tmp)) {
                    tmp.push_back('.');
                    cur->append(tmp);
                    restoreIpAddressesHelper(s, i + 1, dots + 1, cur, result);
                    cur->resize(cur->length() - (i - start + 2));
                }
            }
        }
    }

    bool isValid(const string &s) {
        if (s.empty() || (s[0] == '0' && s != "0")) {
            return false;
        }
        return stoi(s) < 256;
    }
};
