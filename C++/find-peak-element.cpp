// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        int left = 0, right = A.size() - 1;
        
        while (left < right) {
            const auto mid = left + (right - left) / 2;
            if ((mid == 0 || A[mid - 1] < A[mid]) &&
               (mid + 1 == A.size() || A[mid] > A[mid + 1])) {
                return mid;
            } else if (!(mid == 0 || A[mid - 1] < A[mid])) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
       
        return left;
    }
};
