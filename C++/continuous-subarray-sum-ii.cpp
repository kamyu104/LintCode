// Time:  O(n)
// Space: O(n)

class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySumII(vector<int>& A) {
        if (A.empty()) {
            return {-1, -1};
        }
        
        // Calculates the circular / non-circular solution.
        vector<int> circular(2), non_circular(2);
        if (findMaxSubarray(A, &non_circular) >= 
            findCircularMaxSubarray(A, &circular)) {
            return non_circular;
        } else {
            return circular;
        }
    }
    
    // Calculates the non-circular solution.
    int findMaxSubarray(const vector<int>& A, vector<int> *max_i_j) {
        int curr_sum = A[0];
        int max_sum = curr_sum;
        for (int i = 0, j = 1; j < A.size(); ++j) {
            if (curr_sum < 0) {
                i = j;
                curr_sum = 0;
            }
            
            curr_sum += A[j];
            if (curr_sum > max_sum) {
                max_sum = curr_sum;
                (*max_i_j)[0] = i, (*max_i_j)[1] = j;
            }
        }
        
        return max_sum;
    }
    
    // Calculates the solution which is circular.
    int findCircularMaxSubarray(const vector<int>& A, vector<int> *max_i_j) {
        // Max subarray sum starts at index 0 and ends at or before index i.
        vector<int> max_sum_from_start(A.size());
        vector<int> max_j(A.size());
        int sum = A.front();
        max_sum_from_start[0] = sum;
        max_j[0] = 0;
        for (int j = 1; j < A.size(); ++j) {
            sum += A[j];
            if (sum > max_sum_from_start.back()) {
                max_sum_from_start[j] = sum;
                max_j[j] = j;
            } else {
                max_sum_from_start[j] = max_sum_from_start[j - 1];
                max_j[j] = max_j[j - 1];
            }
        }
        
        // Max subarray sum starts at index i + 1 and ends at the last element.
        vector<int> max_sum_to_end(A.size());
        vector<int> max_i(A.size());
        sum = 0;
        max_sum_to_end.back() = sum;
        max_i.back() = 0;
        for (int i = A.size() - 2; i >= 0; --i) {
            sum += A[i + 1];
            if (sum > max_sum_to_end[i + 1]) {
                max_sum_to_end[i] = sum;
                max_i[i] = i + 1;
            } else {
                max_sum_to_end[i] = max_sum_to_end[i + 1];
                max_i[i] = max_i[i + 1];
            }
        }
        
        // Calculates the max subarray which is circular.
        int circular_max = INT_MIN;
        for (int i = 0; i < A.size(); ++i) {
            if (max_sum_from_start[i] + max_sum_to_end[i] > circular_max) {
                circular_max = max_sum_from_start[i] + max_sum_to_end[i];
                (*max_i_j)[0] = max_i[i], (*max_i_j)[1] = max_j[i];
            }
        }
        
        return circular_max;
    }
};
