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
        vector<int> P(5, 0);
        if (values.size() == 0) return false;
        int sum = 0;
        // P[i] = max(values[i] + min(P[i + 2], P[i + 3]),
        //            values[i] + values[i + 1] + min(P[i + 3], P[i + 4]))
        P [(values.size()-1) % 5] = values[values.size()-1];
        sum += values[values.size()-1];
        for (int i = values.size() - 2; i >= 0; --i) {
            sum += values[i];
            int a = i + 2 < values.size() ? P[(i + 2) % 5] : 0;
            int b = i + 3 < values.size() ? P[(i + 3) % 5] : 0;
            int c = i + 4 < values.size() ? P[(i + 4) % 5] : 0;
            P[i % 5] = max(values[i] + min(a, b), 
                       values[i] + values[i + 1] + min(b, c));
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
        vector<int> P(values.size(), 0);
        int sum = 0;
        if (values.size() == 0) return false;
        // P[i] = max(values[i] + min(P[i + 2], P[i + 3]),
        //            values[i] + values[i + 1] + min(P[i + 3], P[i + 4]))
        P[i] = values[values.size() - 1];
        sum += values[values.size() - 1];
        for (int i = values.size() - 2; i >= 0; --i) {
            sum += values[i];
            int a = i + 2 < values.size() ? P[i + 2] : 0;
            int b = i + 3 < values.size() ? P[i + 3] : 0;
            int c = i + 4 < values.size() ? P[i + 4] : 0;
            P[i] = max(values[i] + min(a, b), 
                       values[i] + values[i + 1] + min(b, c));
        }
        
        return P[0] > sum - P[0];
    }
};
