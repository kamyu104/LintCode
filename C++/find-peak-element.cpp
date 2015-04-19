// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        int l = 0;
        int r = A.size() - 1;
        
        while (l < r) {
            int mid = l + (r - l) / 2;
            
            // If mid is a peak
            if ((mid == 0 || A[mid - 1] <= A[mid]) &&
                (mid == A.size() - 1 || A[mid] >= A[mid + 1])) {
                return mid;
            }
            // If mid - 1 is a possible peak
            else if (mid > 0 && A[mid - 1] > A[mid]) {
                r = mid - 1;
            }
            // Else: A[mid - 1] <= A[mid] < A[mid + 1]
            else {
                l = mid + 1;
            }
        }
        
        return l;
    }
};

