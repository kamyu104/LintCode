// Time:  O(k)
// Space: O(1)

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long kthPrimeNumber(int k) {
        long long ugly_number = 0;
        priority_queue<long long, vector<long long>, greater<long long>> heap;

        heap.emplace(3);
        heap.emplace(5);
        heap.emplace(7);

        for (int i = 0; i < k; ++i) {
            if (heap.top() % 3 == 0) {
                ugly_number = heap.top();
                heap.pop();
                heap.emplace(ugly_number * 3);
            }
            else if (heap.top() % 5 == 0) {
                ugly_number = heap.top();
                heap.pop();
                heap.emplace(ugly_number * 3);
                heap.emplace(ugly_number * 5);
            }
            else {
                ugly_number = heap.top();
                heap.pop();
                heap.emplace(ugly_number * 3);
                heap.emplace(ugly_number * 5);
                heap.emplace(ugly_number * 7);
            }
        }
        return ugly_number;
    }
};
