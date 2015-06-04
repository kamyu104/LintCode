// Time:  O(n)
// Space: O(1)

// Greedy solution.
class Solution {
public:
    /**
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int current_sum = 0;
        int total_sum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); ++i) {
            current_sum += gas[i] - cost[i];
            total_sum += gas[i] - cost[i];
            if (current_sum < 0) {
                // It means any gas station in range [start, i] cannot be start.
                current_sum = 0;
                start = i + 1;
            }
        }

        // Check if solution exists, i.e. sum(gas) >= sum(cost).
        if (total_sum >= 0) {
            // 1. route of [start, len(gas) - 1] must be positive
            // 2. route of [0, start - 1] must be negative
            // 3. sum(gas) >= sum(cost), so 1 + 2 >= 0
            // According to the above, start is the gas station we want.
            return start;
        }

        return -1;
    }
};
