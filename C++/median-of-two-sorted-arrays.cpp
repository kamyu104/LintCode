// Time:  O(logn(min(m, n)))
// Space: O(1)

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        if ((A.size() + B.size()) % 2 == 1) {
            return findKthInTwoSortedArrays(A, B, (A.size() + B.size()) / 2 + 1);
        } else {
            return (findKthInTwoSortedArrays(A, B, (A.size() + B.size()) / 2) +
                    findKthInTwoSortedArrays(A, B, (A.size() + B.size()) / 2 + 1)) / 2.0;
        }
    }
    
    int findKthInTwoSortedArrays(const vector<int>& A, const vector<int>& B,
                                 int k) {
        int m = A.size();
        int n = B.size();
        
        // Make sure m is the smaller one.
        if (m > n) {
            return findKthInTwoSortedArrays(B, A, k);
        }
        
        int left = 0;
        int right = m;
        // Find min left s.t. A[left] >= B[k - 1 - left].
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (k - 1 - mid < n && A[mid] >= B[k - 1 - mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        int Ai_minus_1 = left - 1 >= 0 ? A[left - 1] : INT_MIN;
        int Bj = k - 1 - left >= 0 ? B[k - 1 - left] : INT_MIN;
        
        return max(Ai_minus_1, Bj);
    }
};

