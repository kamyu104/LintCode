// Time:  O(n)
// Space: O(n)

class Solution {
public:
    /**
     * @param path the original path
     * @return the simplified path
     */
    string simplifyPath(string& path) {
        vector<string> names;
        vector<string> tokens(move(split(path, '/')));
        for (const auto& token : tokens) {
            if (token == ".." && !names.empty()) {
                names.pop_back();
            } else if (token != ".." && token != "." && !token.empty()) {
                names.emplace_back(token);
            }
        }
        return string("/").append(move(join(names, '/')));
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
    string join(const vector<string>& names, const char& delim) {
        string s;
        if (!names.empty()) {
            ostringstream ss;
            string delim_str;
            delim_str.insert(delim_str.begin(), delim);
            copy(names.cbegin(), prev(names.cend()),
                 ostream_iterator<string>(ss, delim_str.c_str()));
            ss << names.back();
            s = ss.str();
        }
        return s;
    }
};
