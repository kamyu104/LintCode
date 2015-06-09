// Time:  O(m + n)
// Space: O(1)

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int>> &matrix, int target) {
        const int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        const int n = matrix[0].size();
        if  (n == 0) {
            return 0;
        }
        int count = 0;

        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] == target) {
                ++count;
                ++i;
                --j;
            } else if (matrix[i][j] > target) {
                --j;
            } else {
                ++i;
            }
        }

        return count;
    }
};
