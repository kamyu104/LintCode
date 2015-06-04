// Time:  O(logn)
// Space: O(1)

class Solution {
    /**
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        int left = 0;
        int right = A.size() - 1;

        // First min of left s.t. A[left] >= target
        while (left <= right) {
            int mid = left + (right -left) / 2;
            if (A[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};

class Solution2 {
    /**
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        int left = 0;
        int right = A.size();

        // First min of left s.t. A[left] >= target
        while (left < right) {
            int mid = left + (right -left) / 2;
            if (A[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};

class Solution3 {
    /**
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        int left = -1;
        int right = A.size();

        // First min of right s.t. A[right] >= target
        while (right - left > 1) {
            int mid = left + (right -left) / 2;
            if (A[mid] >= target) {
                right = mid;
            } else {
                left = mid;
            }
        }

        return right;
    }
};

