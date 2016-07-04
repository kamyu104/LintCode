// Time:  O(m * n)
// Space: O(m)

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // table[i][j] denotes max_value of using the first i elements
        // to fulfill size j.
        vector<vector<int>> table(2, vector<int>(m + 1, INT_MIN));
        int max_value = 0;
        table[0][0] = 0;

        for (int i = 1; i <= A.size(); ++i) {
            table[i % 2][0] = 0;
            for (int j = 1; j <= m; ++j) {
                // If first i - 1 elements could fulfill the backpack, then
                // first i elements would also do.
                table[i % 2][j] = table[(i - 1) % 2][j];

                // Using the ith element to fulfill the backpack.
                if (j >= A[i - 1] && table[(i - 1) % 2][j - A[i - 1]] >= 0) {
                    table[i % 2][j] = max(table[i % 2][j],
                                          table[(i - 1) % 2][j - A[i - 1]] + V[i - 1]);
                }

                // If it fulfulls size j, update max size.
                if (table[i % 2][j] >= 0) {
                    max_value = max(max_value, table[i % 2][j]);
                }
            }
        }
        return max_value;
    }
};
