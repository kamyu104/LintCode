// Time:  O(k * n^2)
// Space: O(n)

class Solution {
public:
    /**
     * @param A an integer array
     * @param k an integer
     * @return an integer
     */
    int postOffice(vector<int>& A, int k) {
        const int n = A.size();
        if (A.empty() || k >= n) {
            return 0;
        }

        sort(A.begin(), A.end());  // Time:  O(nlogn)

        // Precompute cost.
        // Time:  O(n)
        // Space: O(n)
        vector<int> before_cost(n), after_cost(n);
        computeCost(A, &before_cost, &after_cost);

        // DP of sum.
        // Time:  O(k * n^2)
        // Space: O(n)
        // sum[i][j] denotes the smallest sum of
        // picking i post offices for the first j houses.
        vector<vector<int>> sum(2, vector<int>(A.size() + 1, INT_MAX));
        sum[0][0] = 0;
        for (int i = 1; i <= k; ++i) {
            for (int j = 0; j <= n; ++j) {
                // We can skip this line due to sum[i][j] <= sum[i - 2][j]
                // sum[i % 2][j] = INT_MAX;
                for (int r = 1; r <= j; ++r) {
                    if (sum[(i - 1) % 2][j - r] != INT_MAX) {
                        sum[i % 2][j] = min(sum[i % 2][j],
                                            sum[(i - 1) % 2][j - r] +
                                            minCost(A,
                                                    before_cost, after_cost,
                                                    j - r, j - 1));
                    }
                }
            }
        }
        return sum[k % 2][n];
    }

    void computeCost(const vector<int>& A,
                     vector<int> *before_cost, vector<int> *after_cost) {
        const int n = A.size();
        for (int i = 1; i < n; ++i) {
            // before_cost[i] = Sum(A[i] - A[k]) for k < i
            (*before_cost)[i] = (*before_cost)[i - 1] +
                                i * (A[i] - A[i - 1]);
        }
        for (int i = n - 2; i >= 0; --i) {
            // after_cost[i] = Sum(A[k] - A[i]) for k > i
            (*after_cost)[i] = (*after_cost)[i + 1] +
                               (n - 1 - i) * (A[i + 1] - A[i]);
        }
    }

    int minCost(const vector<int>& A,
                const vector<int> &before_cost, const vector<int> &after_cost,
                const int i, const int j) {
            // Min cost of building a post office between house (i, j).
            // This post office must be in median position.
            const int n = A.size();
            int mid = i + (j - i) / 2;
            int before_mid = before_cost[mid] -
                             (before_cost[i] + i * (A[mid] - A[i]));
            int after_mid = after_cost[mid] -
                            (after_cost[j] + (n - 1 - j) * (A[j] - A[mid]));
            return before_mid + after_mid;
    }
};

// Time:  O(n^3)
// Space: O(n^2)
class Solution2 {
public:
    /**
     * @param A an integer array
     * @param k an integer
     * @return an integer
     */
    int postOffice(vector<int>& A, int k) {
        const int n = A.size();
        if (A.empty() || k >= n) {
            return 0;
        }

        sort(A.begin(), A.end());  // Time:  O(nlogn)

        // Precompute cost.
        // Time:  O(n^3)
        // Space: O(n^2)
        vector<vector<int>> cost(A.size() + 1, vector<int>(A.size() + 1, 0));
        computeMinCost(A, &cost);

        // DP of sum.
        // Time:  O(k * n^2)
        // Space: O(k * n)
        // sum[i][j] denotes the smallest sum of
        // picking i post offices for the first j houses.
        vector<vector<int>> sum(k + 1, vector<int>(A.size() + 1, INT_MAX));
        sum[0][0] = 0;
        for (int i = 1; i <= k; ++i) {
            for (int j = 0; j < n; ++j) {
                if (sum[i - 1][j] != INT_MAX) {
                    for (int r = 1; j + r <= n; ++r) {
                       sum[i][j + r] = min(sum[i][j + r],
                                           sum[i - 1][j] + cost[j + 1][j + r]);
                    }
                }
            }
        }
        return sum[k][n];
    }

    void computeMinCost(const vector<int>& A, vector<vector<int>> *cost) {
        // Min cost of building a post office between house (i, j).
        // This post office must be in median position.
        const int n = A.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int mid = (i + j) / 2;
                for (int r = i; r <= mid; ++r) {
                    (*cost)[i + 1][j + 1] += A[mid] - A[r];
                }
                for (int r = mid + 1; r <= j; ++r) {
                    (*cost)[i + 1][j + 1] += A[r] - A[mid];
                }
            }
        }
    }
};
