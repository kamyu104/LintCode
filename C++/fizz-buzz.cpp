// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * param n: As description.
     * return: A list of strings.
     */
    vector<string> fizzBuzz(int n) {
        vector<string> result;

        for (int i = 1; i <= n; ++i) {
            if (i % 15 == 0) {
                result.emplace_back("fizz buzz");
            } else if (i % 5 == 0) {
                result.emplace_back("buzz");
            } else if (i % 3 == 0) {
                result.emplace_back("fizz");
            } else {
                result.emplace_back(to_string(i));
            }
        }

        return result;
    }
};
