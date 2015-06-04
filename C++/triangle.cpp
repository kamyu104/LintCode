// Time:  O(n)
// Space: O(n)

#include <algorithm>
#include <vector>

using std::min;
using std::vector;

class Solution {
    public:
        /**
         * @param triangle: a list of lists of integers.
         * @return: An integer, minimum path sum.
         */
        int minimumTotal(vector<vector<int>> &triangle) {
            // for empty input
            if (triangle.empty()) {
                return 0;
            }

            // Stores the minimum path sum of triangle[i - 1].
            vector<int> prev_row(triangle.front());
            for (size_t i = 1; i < triangle.size(); ++i) {
                // Stores the minimum path sum of triangle[i].
                vector<int> curr_row(triangle[i]);
                curr_row.front() += prev_row.front();  // For the first element.
                for (size_t j = 1; j < curr_row.size() - 1; ++j) {
                    curr_row[j] += min(prev_row[j - 1], prev_row[j]);
                }
                curr_row.back() += prev_row.back();  // For the last element.

                prev_row.swap(curr_row);
            }
            return *min_element(prev_row.cbegin(), prev_row.cend());
        }
};

