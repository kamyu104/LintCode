// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param costs n x 3 cost matrix
     * @return an integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) {
            return 0;
        }

        vector<vector<int>> min_cost(2, costs[0]);

        const int n = costs.size();
        for (int i = 1; i < n; ++i) {
            min_cost[i % 2][0] = costs[i][0] +
                                 min(min_cost[(i - 1) % 2][1],
                                     min_cost[(i - 1) % 2][2]);
            min_cost[i % 2][1] = costs[i][1] +
                                 min(min_cost[(i - 1) % 2][0],
                                     min_cost[(i - 1) % 2][2]);
            min_cost[i % 2][2] = costs[i][2] +
                                 min(min_cost[(i - 1) % 2][0],
                                     min_cost[(i - 1) % 2][1]);
        }

        return min(min_cost[(n - 1) % 2][0],
                   min(min_cost[(n - 1) % 2][1], min_cost[(n - 1) % 2][2]));
    }
};
