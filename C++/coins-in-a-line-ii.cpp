// Time:  O(n)
// Space: O(1)

// DP with rolling window.
class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        vector<int> P(5);
        int sum = 0;
        for (int i = values.size() - 1; i >= 0; --i) {
            sum += values[i];
            const int a = i + 1 < values.size() ? values[i + 1]: 0;
            const int b = i + 2 < values.size() ? P[(i + 2) % 5] : 0;
            const int c = i + 3 < values.size() ? P[(i + 3) % 5] : 0;
            const int d = i + 4 < values.size() ? P[(i + 4) % 5] : 0;
            // P[i] = max(values[i] + min(P[i + 2], P[i + 3]),
            //            values[i] + values[i + 1] + min(P[i + 3], P[i + 4]))
            P[i % 5] = max(values[i] + min(b, c), values[i] + a + min(c, d));
        }

        return P[0] > sum - P[0];
    }
};


// Time:  O(n)
// Space: O(n)
class Solution2 {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        vector<int> P(values.size());
        int sum = 0;
        for (int i = values.size() - 1; i >= 0; --i) {
            sum += values[i];
            const int a = i + 1 < values.size() ? values[i + 1]: 0;
            const int b = i + 2 < values.size() ? P[i + 2] : 0;
            const int c = i + 3 < values.size() ? P[i + 3] : 0;
            const int d = i + 4 < values.size() ? P[i + 4] : 0;
            // P[i] = max(values[i] + min(P[i + 2], P[i + 3]),
            //            values[i] + values[i + 1] + min(P[i + 3], P[i + 4]))
            P[i] = max(values[i] + min(b, c),  values[i] + a + min(c, d));
        }

        return P[0] > sum - P[0];
    }
};
