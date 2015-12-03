// Time:  O(n * (C(2n, n) - C(2n, n - 1))) = Catalan numbers
// Space: O(n)

class Solution {
public:
    /**
     * @param n n pairs
     * @return All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string cur;
        generateParenthesisHelper(n, n, &cur, &result);
        return result;
    }

    void generateParenthesisHelper(
        int left, int right,
        string *cur, vector<string> *result) {

        if (!left && !right) {
            result->emplace_back(*cur);
        }
        if (left > 0) {
            cur->push_back('(');
            generateParenthesisHelper(left - 1, right, cur, result);
            cur->pop_back();
        }
        if (left < right) {
            cur->push_back(')');
            generateParenthesisHelper(left, right - 1, cur, result);
            cur->pop_back();
        }
    }
};
