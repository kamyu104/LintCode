// Time:  O(k * n * t), n is size of array, k is the largest number in array, t is target
// Space: O(k)

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        const int n = A.size();
        const int max_num = 100;

        // min_cost[i][j] denotes the min cost of the first i elements
        // with target j.
        vector<vector<int>> min_cost(2, vector<int>(max_num + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= max_num; ++j) {
                // min_cost[i][j] = abs(A[i - 1] - j) +
                //                  min(min_cost[i][k],
                //                  for each k s.t. | k - j | <= target)
                int upper = min(max_num, j + target);
                int lower = max(1, j - target);
                min_cost[i % 2][j] = INT_MAX;
                for (int k = lower; k <= upper; ++k) {
                    min_cost[i % 2][j] = min(min_cost[i % 2][j],
                                             min_cost[(i - 1) % 2][k]);
                }
                min_cost[i % 2][j] += abs(A[i - 1] - j);
            }
        }

        // return min of min_cost[n] excluding min_cost[n][0]
        return *min_element(next(min_cost[n % 2].cbegin()), min_cost[n % 2].cend());
    }
};
