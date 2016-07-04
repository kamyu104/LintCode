// Time:  O(m * n)
// Space: O(m)

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // table[i][j] denotes whether using the first i elements
        // could fulfill size j.
        vector<vector<bool>> table(2, vector<bool>(m + 1, false));
        int max_size = 0;
        table[0][0] = true;

        for (int i = 1; i <= A.size(); ++i) {
            table[i % 2][0] = true;
            for (int j = 1; j <= m; ++j) {
                // If first i - 1 elements could fulfill the backpack, then
                // first i elements would also do.
                table[i % 2][j] = table[(i - 1) % 2][j];

                // Using the ith element to fulfill the backpack.
                if (j >= A[i - 1]) {
                    table[i % 2][j] = table[i % 2][j]
                    || table[(i - 1) % 2][j - A[i - 1]];
                }

                // If it fulfills size j, update max size.
                if (table[i % 2][j]) {
                    max_size = max(max_size, j);
                }
            }
        }

        return max_size;
    }
};
