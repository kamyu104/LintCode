// Time:  O(n)
// Space: O(1)

// DP Solution
class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) {
            return 0;
        }

        int hold1 = INT_MIN, hold2 = INT_MIN;
        int release1 = INT_MIN, release2 = INT_MIN;

        for (const auto& p : prices) {
            hold1 = max(hold1, -p);
            release1 = max(release1, hold1 + p);
            hold2 = max(hold2, release1 - p);
            release2 = max(release2, hold2 + p);
        }

        return release2;
    }
};

// Generic Solution
class Solution2 {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) {
            return 0;
        }

        const int k = 2;

        // Optimized solution for unlimited transactions.
        if (k >= prices.size() / 2) {
            return maxUnlimitedTransactionsProfit(prices);
        }

        // Get max profit at most k transactions.
        return maxAtMostKTransactionsProfit(prices, k);
    }

    int maxUnlimitedTransactionsProfit(vector<int> &prices) {
        int profit = 0;
        for (int i = 0; i < prices.size() - 1; ++i) {
            profit += max(0, prices[i + 1] - prices[i]);
        }
        return profit;
    }

    int maxAtMostKTransactionsProfit(vector<int> &prices, int k) {
        // max_sell[j] short for max_sell[i][j]
        // denotes as max profit at most j - 1 buy and sell transactions
        // and buy the ith prices in the first i prices.
        vector<int> max_sell(k + 1, INT_MIN);

        // max_buy[j] short for max_buy[i][j]
        // denotes as max profit at most j buy and sell transactions
        // and sell the ith prices in the first i prices.
        vector<int> max_buy(k + 1, INT_MIN);

        max_sell[0] = max_buy[0] = 0;

        for (int i = 0; i < prices.size(); ++i) {
            // Update max profix in [i / 2]  + 1 transactions.
            for (int j = 1; j <= min(k, i / 2 + 1); ++j) {
                // Update max profit of j-th buy
                // by (j-1)-th sell - prices[i].
                max_buy[j] = max(max_buy[j], max_sell[j - 1] - prices[i]);

                // Update max profit of jth sell
                // by max(j-th buy + prices[i], (j-1)-th sell]).
                max_sell[j] = max(max_sell[j], max_buy[j] + prices[i]);
            }
        }

        return max_sell[k];
    }
};
