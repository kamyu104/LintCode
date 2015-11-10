// Time:  O(n)
// Space: O(1)

// Catalan Number: C(2n, n) - C(2n, n - 1)
class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        if (n == 0) {
            return 1;
        }
        return combination(2 * n, n) - combination(2 * n, n - 1);
    }

    int combination(const int  n, const int k) {
        long long count = 1;
        // C(n, k) = (n) / 1 * (n - 1) / 2 ... * (n - k + 1) / k
        for (int i = 1; i <= k; ++i) {
            count = count * (n - i + 1) / i;
        }

        return count;
    }
};

// Time:  O(n^2)
// Space: O(n)
class Solution2 {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        vector<int> num(n + 1, 0);
        num[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                num[i] += num[j] * num[i - 1 - j];
            }
        }
        return num[n];
    }
};
