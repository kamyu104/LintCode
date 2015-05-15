// Time:  O(max(m, n))
// Space: O(1)

class Solution {
    /**
     * @param A: An integer matrix
     * @return: The index of the peak
     */
    public List<Integer> findPeakII(int[][] A) {
        int upper = 0, down = A.length - 1;
        int left = 0, right = A[0].length - 1;

        while (upper < down && left < right) {
            int height = down - upper + 1;
            int width = right - left + 1;
            
            // T(m, n) = T(m, n / 2) + O(m) = T(m / 2, n / 2) + O(m) + O(n / 2) = ... = O(2m) + O(2n) = O(max(m, n))
            if (width > height) { // Vertical split.
                int mid_j = left + (right - left) / 2;
                int left_max = 0, central_max = 0, right_max = 0;
                int max_i = -1, max_j = -1;
                for (int i = upper + 1; i < down; ++i) {
                    if (A[i][mid_j] > central_max) {
                        max_i = i; max_j = mid_j;
                        central_max = A[i][mid_j];
                    }
                    left_max = Math.max(left_max, A[i][mid_j - 1]);
                    right_max = Math.max(right_max, A[i][mid_j +  1]);
                }
                if (left_max > central_max && left_max > right_max) { // Find left.
                    right = mid_j;
                } else if (right_max > central_max && right_max > left_max) { // Find right.
                    left = mid_j;
                } else { // Find one peak.
                    ArrayList<Integer> numbers = new ArrayList<Integer>();
                    numbers.add(max_i);
                    numbers.add(max_j);
                    return numbers;
                }
            } else { // Horizontal split.
                int mid_i = upper + (down - upper) / 2;
                int upper_max = 0, central_max = 0, down_max = 0;
                int max_i = -1, max_j = -1;
                for (int j = left + 1; j < right; ++j) {
                    if (A[mid_i][j] > central_max) {
                        max_i = mid_i; max_j = j;
                        central_max = A[mid_i][j];
                    }
                    upper_max = Math.max(upper_max, A[mid_i - 1][j]);
                    down_max = Math.max(down_max, A[mid_i + 1][j]);
                }
                if (upper_max > central_max && upper_max > down_max) { // Find upper.
                    down = mid_i;
                } else if (down_max > central_max && down_max > upper_max) { // Find down.
                    upper = mid_i;
                } else { // Find one peak.
                    ArrayList<Integer> numbers = new ArrayList<Integer>();
                    numbers.add(max_i);
                    numbers.add(max_j);
                    return numbers;
                }
            } 
            
        }
        
        ArrayList<Integer> numbers = new ArrayList<Integer>();
        numbers.add(-1);
        numbers.add(-1);

        return numbers; // Not found.    
    }
}

