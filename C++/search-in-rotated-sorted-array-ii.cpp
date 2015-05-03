// Time:  O(logn)
// Space: O(1)

class Solution {
    /**
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean
     */
public:
    bool search(vector<int> &A, int target) {
        int left = 0;
        int right = A.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (A[mid] == target) {
                return true;
            }
            if (A[left] < A[mid]) {
                if (A[left] <= target && target < A[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (A[left] > A[mid]){
                if (A[mid] < target and target <= A[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                ++left;
            }
        }
        
        return false;
    }
};

class Solution2 {
    /**
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean
     */
public:
    bool search(vector<int> &A, int target) {
        int left = 0;
        int right = A.size();
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (A[mid] == target) {
                return true;
            }
            if (A[left] < A[mid]) {
                if (A[left] <= target && target < A[mid]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else if (A[left] > A[mid]){
                if (A[mid] < target and target <= A[right - 1]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            } else {
                ++left;
            }
        }
        
        return false;
    }
};
