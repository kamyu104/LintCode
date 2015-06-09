// Time:  O(n)
// Space: O(n)

class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The Reverse Polish notation of this expression
     */
    vector<string> convertToRPN(vector<string> &expression) {
        vector<string> output;
        infixToPostfix(expression, output);
        return output;
    }

    // Convert Infix to Postfix Expression.
    void infixToPostfix(const vector<string>& infix, vector<string>& postfix) {
        stack<string> s;
        for (auto tok : infix) {
            if (atoi(tok.c_str())) {
                postfix.emplace_back(tok);
            } else if (tok == "(") {
                s.emplace(tok);
            } else if (tok == ")") {
                while (!s.empty()) {
                    tok = s.top();
                    s.pop();
                    if (tok == "(") {
                        break;
                    }
                    postfix.emplace_back(tok);
                }
            } else {
                while (!s.empty() && precedence(tok) <= precedence(s.top())) {
                    postfix.emplace_back(s.top());
                    s.pop();
                }
                s.emplace(tok);
            }
        }
        while (!s.empty()) {
            postfix.emplace_back(s.top());
            s.pop();
        }
    }

    int precedence(string x) {
        if (x == "(") {
            return 0;
        } else if (x == "+" || x == "-") {
            return 1;
        } else if (x == "*" || x == "/") {
            return 2;
        }
        return 3;
    }
};
