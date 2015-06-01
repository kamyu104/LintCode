// Time:  O(n)
// Space: O(n)

class Solution {
public:
    /**
     * @param path the original path
     * @return the simplified path
     */
    string simplifyPath(string& path) {
        vector<string> stk;
        vector<string> tokens(move(split(path, '/')));
        for (const auto& token : tokens) {
            if (token == ".." && !stk.empty()) {
                stk.pop_back();
            } else if (token != ".." && token != "." && !token.empty()) {
                stk.emplace_back(token);
            }
        }
        return string("/").append(move(join(stk, '/')));
    }
    
    // Split string by delimitor.
    vector<string> split(const string& s, const char delim) {
        vector<string> tokens;
        stringstream ss(s);
        string token;
        while (getline(ss, token, delim)) {
            tokens.emplace_back(token);
        }
        return tokens;
    }
    
    // Join strings with delimitor.
    string join(const vector<string>& stk, const char& delim) {
        string s;
        if (!stk.empty()) {
            ostringstream ss;
            string delim_str;
            delim_str.insert(delim_str.begin(), delim);
            copy(stk.cbegin(), prev(stk.cend()), 
                 ostream_iterator<string>(ss, delim_str.c_str()));
            ss << stk.back();
            s = ss.str();
        }
        return s;
    }
};
