// Time:  O(n) ~ O(n^2)
// Space: O(1)

// In-place insertion sort. (stable)
class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers(vector<int>& A) {
        for (int n = 0; n < A.size(); ++n) {
            for (int i = n - 1; i >= 0 && A[i] > A[i + 1]; --i) {
                swap(A[i], A[i + 1]);
            }
        }
    }
};

// Time:  O(n^2)
// Space: O(1)
// Bubble sort. (stable)
class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers(vector<int>& A) {
        for (int n = 0; n < A.size(); ++n) {
            for (int i = 0; i + 1 < static_cast<int>(A.size()) - n; ++i) {
                if (A[i] > A[i + 1]) {
                    swap(A[i], A[i + 1]);
                }
            }
        }
    }
};

// Time:  O(n^2)
// Space: O(1)
// Selection sort. (unstable)
class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers(vector<int>& A) {
        for (int n = 0; n < A.size(); ++n) {
            int min_idx = n;
            for (int i = n + 1; i < A.size(); ++i) {
                if (A[i] < A[min_idx]) {
                    min_idx = i;
                }
            }
            swap(A[n], A[min_idx]);
        }
    }
};
