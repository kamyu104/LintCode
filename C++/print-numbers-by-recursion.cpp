// Time:  O(n)
// Space: O(n)

class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        vector<int> result;
        numbersByRecursionHelper(0, n, result);
        return result;
    }

    // Construct the numbers by the current digit count.
    void numbersByRecursionHelper(int depth, int n, vector<int>& result) {
        if (depth == n) {
            return;
        }

        if (depth == 0) {  // Initiate the result.
            for (size_t d = 1; d <= 9; ++d) {
                result.emplace_back(d);
            }
        } else {  // Construct the numbers by the previous result.
            const size_t count = result.size();
            for (size_t d = 1; d <= 9; ++d) {
                result.emplace_back(d * pow(10, depth));
                for (size_t i = 0; i < count; ++i) {
                    result.emplace_back(result[i] + d * pow(10, depth));
                }
            }
        }
        // Construct the numbers in the next depth.
        numbersByRecursionHelper(depth + 1, n, result);
    }

};
