// Time:  O(n)
// Space: O(n)

/**
 * Definition of ExpressionTreeNode:
 * class ExpressionTreeNode {
 * public:
 *     string symbol;
 *     ExpressionTreeNode *left, *right;
 *     ExpressionTreeNode(string symbol) {
 *         this->symbol = symbol;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The root of expression tree
     */
    ExpressionTreeNode* build(vector<string> &expression) {
        if (expression.empty()) {
            return 0;
        }
        vector<string> prefix;
        infixToPrefix(expression, prefix);
        int start = 0;
        return buildExpressionTree(prefix, start);
    }

    // Build expression tree by prefix expression.
    ExpressionTreeNode* buildExpressionTree(vector<string>& prefix, int& start) {
        if (prefix.empty()) {
            return nullptr;
        }
        ExpressionTreeNode *node = new ExpressionTreeNode(prefix[start++]);
        if (is_operator(prefix[start - 1])) {
            node->left = buildExpressionTree(prefix, start);
            node->right = buildExpressionTree(prefix, start);
        }
        return node;
    }

    bool is_operator(const string &op) {
        return op.length() == 1 && string("+-*/").find(op) != string::npos;
    }

    // Convert Infix to Prefix Expression.
    void infixToPrefix(vector<string>& infix, vector<string>& prefix) {
        reverse(infix.begin(), infix.end());
        stack<string> s;
        for (auto& tok : infix) {
            if (atoi(tok.c_str())) {
                prefix.emplace_back(tok);
            } else if (tok == ")") {
                s.emplace(tok);
            } else if (tok == "(") {
                while (!s.empty()) {
                    tok = s.top();
                    s.pop();
                    if (tok == ")") {
                        break;
                    }
                    prefix.emplace_back(tok);
                }
            } else {
                while (!s.empty() && precedence(tok) < precedence(s.top())) {
                    prefix.emplace_back(s.top());
                    s.pop();
                }
                s.emplace(tok);
            }
        }
        while (!s.empty()) {
            prefix.emplace_back(s.top());
            s.pop();
        }
        reverse(prefix.begin(), prefix.end());
    }

    int precedence(string x) {
        if (x == ")") {
            return 0;
        } else if (x == "+" || x == "-") {
            return 1;
        } else if (x == "*" || x == "/") {
            return 2;
        }
        return 3;
    }

};
