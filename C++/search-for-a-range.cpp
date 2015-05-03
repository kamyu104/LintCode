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
        auto start = lower_bound(A.begin(), A.end(), target);
        auto end = upper_bound(A.begin(), A.end(), target);
        if (start != A.end() && *start == target) {
            return {start - A.begin(), end - A.begin() - 1};
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
        int begin = lower_bound(A, target);
        int end = upper_bound(A, target);
        
        if(begin < A.size() && A[begin] == target)
            return {begin, end - 1};
        
        return {-1, -1};
    }
    
private:
    int lower_bound(vector<int> &A, int target) {
        int left = 0;
        int right = A.size();
        // Find min left s.t. A[left] >= target.
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(A[mid] >= target) {
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
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(A[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

