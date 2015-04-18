// Time:  O(n)
// Space: O(1)

#include <algorithm>
#include <vector>

using std::swap;
using std::vector;

class Solution {
    public:
        /**    
         * @param A: a vector of integers
         * @return: an integer
         */
        int firstMissingPositive(vector<int> A) {
            // Record which values are present by writing A[i] to index A[i] - 1 if A[i]
            // is between 1 and A.size(), inclusive. We save the value at index
            // A[i] - 1 by swapping it with the entry at i. If A[i] is negative or
            // greater than n, we just advance i.
            size_t i = 0;
            while (i < A.size()) {
                if (A[i] > 0 && A[i] <= A.size() &&
                        A[A[i] - 1] != A[i]) {
                    swap(A[i], A[A[i] - 1]);
                } else {
                    ++i;
                }
            }

            // Second pass through A to search for the first index i such that
            // A[i] != i+1, indicating that i + 1 is absent. If all numbers between 1
            // and A.size() are present, the smallest missing positive is A.size() + 1.
            for (size_t i = 0; i < A.size(); ++i) {
                if (A[i] != i + 1) {
                    return i + 1;
                }
            }
            return A.size() + 1;
        }
};

