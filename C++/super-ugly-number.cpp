// Time:  O(n * logk) ~ O(n * k)
// Space: O(n + k)

// Heap solution. (308ms)
class Solution {
public:
    /**
     * @param n a positive integer
     * @param primes the given prime list
     * @return the nth super ugly number
     */
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> heap;
        vector<int> uglies(n), idx(primes.size()), ugly_by_last_prime(n);
        uglies[0] = 1;

        for (int i = 0; i < primes.size(); ++i) {
            heap.emplace(primes[i], i);
        }
        for (int i = 1; i < n; ++i) {
            int k;
            tie(uglies[i], k) = heap.top();
            heap.pop();
            ugly_by_last_prime[i] = k;
            while (ugly_by_last_prime[++idx[k]] > k);  // worst time: O(k)
            heap.emplace(uglies[idx[k]] * primes[k], k);
        }
        return uglies[n - 1];
    }
};
