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
            }
            else if (ugly_number % 5 == 0) {
                heap.emplace(ugly_number * 3);
                heap.emplace(ugly_number * 5);
            }
            else {
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
            }
            else if (ugly_number % 5 == 0) {
                bst.emplace(ugly_number * 3);
                bst.emplace(ugly_number * 5);
            }
            else {
                bst.emplace(ugly_number * 3);
                bst.emplace(ugly_number * 5);
                bst.emplace(ugly_number * 7);
            }
        }
        return ugly_number;
    }
};
