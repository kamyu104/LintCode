// Time:  O(logn)
// Space: O(1)

class Solution {
    /**
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        const auto start = lower_bound(A.cbegin(), A.cend(), target);
        const auto end = upper_bound(A.cbegin(), A.cend(), target);
        if (start != A.cend() && *start == target) {
            return {start - A.cbegin(), end - A.cbegin() - 1};
        }
        return {-1, -1};
    }
};

class Solution2 {
    /**
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        const int begin = lower_bound(A, target);
        const int end = upper_bound(A, target);

        if (begin < A.size() && A[begin] == target)
            return {begin, end - 1};

        return {-1, -1};
    }

private:
    int lower_bound(vector<int> &A, int target) {
        int left = 0;
        int right = A.size();
        // Find min left s.t. A[left] >= target.
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (A[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    int upper_bound(vector<int> &A, int target) {
        int left = 0;
        int right = A.size();
        // Find min left s.t. A[left] > target.
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (A[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

