// Time:  O(k)
// Space: O(1)

// Heap solution.
class Solution {
public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long kthPrimeNumber(int k) {
        long long ugly_number = 0;
        priority_queue<long long, vector<long long>, greater<long long>> heap;

        heap.emplace(1);
        for (int i = 0; i <= k; ++i) {
            ugly_number = heap.top();
            heap.pop();
            if (ugly_number % 3 == 0) {
                heap.emplace(ugly_number * 3);
            } else if (ugly_number % 5 == 0) {
                heap.emplace(ugly_number * 3);
                heap.emplace(ugly_number * 5);
            } else {
                heap.emplace(ugly_number * 3);
                heap.emplace(ugly_number * 5);
                heap.emplace(ugly_number * 7);
            }
        }
        return ugly_number;
    }
};

// BST solution.
class Solution2 {
public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long kthPrimeNumber(int k) {
        long long ugly_number = 0;
        set<long long> bst;

        bst.emplace(1);
        for (int i = 0; i <= k; ++i) {
            ugly_number = *bst.cbegin();
            bst.erase(bst.cbegin());
            if (ugly_number % 3 == 0) {
                bst.emplace(ugly_number * 3);
            } else if (ugly_number % 5 == 0) {
                bst.emplace(ugly_number * 3);
                bst.emplace(ugly_number * 5);
            } else {
                bst.emplace(ugly_number * 3);
                bst.emplace(ugly_number * 5);
                bst.emplace(ugly_number * 7);
            }
        }
        return ugly_number;
    }
};

// Time:  O(k)
// Space: O(k)
// DP solution.
class Solution3 {
public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long kthPrimeNumber(int k) {
        vector<long long> uglies(k + 1);
        uglies[0] = 1;
    
        long long f3 = 3, f5 = 5, f7 = 7;
        int idx3 = 0, idx5 = 0, idx7 = 0;
    
        for (int i = 1; i < k; ++i) {
            long long min_val = min(min(f3, f5), f7);
            uglies[i] = min_val;
    
            if (min_val == f3) {
                f3 = 3 * uglies[++idx3];
            }
            if (min_val == f5) {
                f5 = 5 * uglies[++idx5];
            }
            if (min_val == f7) {
                f7 = 7 * uglies[++idx7];
            }
        }

        return uglies[k];
    }
};
