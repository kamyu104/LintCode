// Time:  O(n)
// Space: O(n)

class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) {
            return 0;
        }
        stack<string> s;
        for (const auto& tok : tokens) {
            if (!is_operator(tok)) {
                s.emplace(tok);
            } else {
                int y = stoi(s.top());
                s.pop();
                int x = stoi(s.top());
                s.pop();
                if (tok[0] == '+') {
                    x += y;
                } else if (tok[0] == '-') {
                    x -= y;
                } else if (tok[0] == '*') {
                    x *= y;
                } else {
                    x /= y;
                }
                s.emplace(to_string(x));
            }
        }
        return stoi(s.top());
    }

    bool is_operator(const string &op) {
        return op.length() == 1 && string("+-*/").find(op) != string::npos;
    }
};
