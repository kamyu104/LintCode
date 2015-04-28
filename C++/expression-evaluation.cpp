// Time:  O(n)
// Space: O(n)

class Solution {
public:
    /**
     * @param expression: a vector of strings;
     * @return: an integer
     */
    int evaluateExpression(vector<string> &expression) {
        if (expression.empty()) {
            return 0;
        }
        vector<string> postfix;
        infixToPostfix(expression, postfix);
        return evalPostfixExpression(postfix);
    }
    
    // Convert Infix to Postfix Expression.
    void infixToPostfix(vector<string>& infix, vector<string>& postfix) {
        stack<string> s;
        for (auto tok : infix) {
            if (atoi(tok.c_str())) {
                postfix.push_back(tok);
            }
            else if (tok == "(") {
                s.push(tok);
            }
            else if (tok == ")") {
                while (!s.empty()) {
                    tok = s.top();
                    s.pop();
                    if (tok == "(")
                        break;
                    postfix.push_back(tok);
                }
            } else {
                while(!s.empty() && precedence(tok) <= precedence(s.top())) {
                    postfix.push_back(s.top());
                    s.pop();
                }
                s.push(tok);
            }
        }
        while (!s.empty()) {
            postfix.push_back(s.top());
            s.pop();
        }
    }
    
    int precedence(string x) {
        if(x == "(") {
            return 0;
        }
        else if(x == "+" || x == "-") {
            return 1;
        }
        else if(x == "*" || x== "/") {
            return 2;
        }
        return 3;
    }
    
    
    // Evaluate Postfix Expression.
    int evalPostfixExpression(vector<string> &postfix) {
        if (postfix.empty()) {
            return 0;
        }
        stack<string> s;
        for(auto& tok : postfix) {
            if(!is_operator(tok)) {
                s.push(tok);
            }
            else {
                int y = stoi(s.top());
                s.pop();
                int x = stoi(s.top());
                s.pop();
                if(tok[0] == '+') {
                    x += y;
                }
                else if (tok[0] == '-') {
                    x -= y;
                }
                else if (tok[0] == '*') {
                    x *= y;
                }
                else {
                    x /= y;
                }
                s.push(to_string(x));
            }
        }
        return stoi(s.top());
    }
    
    bool is_operator(const string &op) {
        return op.length() == 1 && string("+-*/").find(op) != string::npos;
    }
};