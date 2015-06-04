// Time:  O(k * n)
// Space: O(k)

class Solution {
public:
    /**
     * @param k: An integer
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(int k, vector<int> &prices) {
        // Optimized solution for unlimited transactions.
        if (k >= prices.size() / 2) {
            return maxUnlimitedTransactionsProfit(prices);
        }

        // Get max profit at most k transactions.
        return maxAtMostKTransactionsProfit(prices, k);
    }

    int maxUnlimitedTransactionsProfit(const vector<int>& prices) {
        int profit = 0;
        for (int i = 0; i < static_cast<int>(prices.size()) - 1; ++i) {
            profit += max(0, prices[i + 1] - prices[i]);
        }
        return profit;
    }

    int maxAtMostKTransactionsProfit(const vector<int>& prices, const int k) {
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
