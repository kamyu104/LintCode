// Time:  O(n^2)
// Space: O(1)

// Bubble sort.
class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers(vector<int>& A) {
        for (int n = 0; n + 1 < A.size(); ++n) {
            for (int i = 0; i + 1 + n < A.size(); ++i) {
                if (A[i] > A[i + 1]) {
                    swap(A[i], A[i + 1]);
                }
            }
        }
    }
};
