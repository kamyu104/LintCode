// Time:  O(m + n)
// Space: O(1)

class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements,
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        int i = m + n;
        while (m > 0 && n > 0) {
            if (A[m - 1] > B[n - 1]) {
                A[i - 1] = A[m - 1];
                --m;
            } else {
                A[i - 1] = B[n - 1];
                --n;
            }
            --i;
        }

        while (n > 0) {
            A[i - 1] = B[n - 1];
            --n;
            --i;
        }
    }
};

