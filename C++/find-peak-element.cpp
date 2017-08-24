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
            if (A[mid] > A[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
       
        return left;
    }
};
