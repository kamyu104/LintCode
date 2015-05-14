# Time:  O(max(m, n))
# Space: O(1)

class Solution:
    #@param A: An list of list integer 
    #@return: The index of position is a list of integer, for example [2,2]
    def findPeakII(self, A):
        upper, down = 0, len(A) - 1
        left, right = 0, len(A[0]) - 1

        while upper < down and left < right:
            height = down - upper + 1
            width = right - left + 1
            
            # T(m, n) = T(m, n / 2) + O(m) = T(m / 2, n / 2) + O(m) + O(n / 2) = ... = O(2m) + O(2n) = O(max(m, n))
            if width > height: # Vertical split.
                mid_j = left + (right - left) / 2
                left_max, central_max, right_max = 0, 0, 0
                max_i, max_j = -1, -1
                for i in xrange(upper+1, down):
                    if A[i][mid_j] > central_max:
                        max_i, max_j = i, mid_j
                        central_max = A[i][mid_j]
                    left_max = max(left_max, A[i][mid_j - 1])
                    right_max = max(right_max, A[i][mid_j +  1])
                    
                if left_max > central_max and left_max > right_max: # Find left.
                    right = mid_j
                elif right_max > central_max and right_max > left_max: # Find right.
                    left = mid_j
                else: # Find one peak.        
                    return [max_i, max_j]
                    
            else: # Horizontal split.
                mid_i = upper + (down - upper) / 2
                upper_max, central_max, down_max = 0, 0, 0
                max_i, max_j = -1, -1
                for j in xrange(left + 1, right):
                    if A[mid_i][j] > central_max:
                        max_i, max_j = mid_i, j
                        central_max = A[mid_i][j]
                    upper_max = max(upper_max, A[mid_i - 1][j])
                    down_max = max(down_max, A[mid_i + 1][j])
                    
                if upper_max > central_max and upper_max > down_max: # Find upper.
                    down = mid_i
                elif down_max > central_max and down_max > upper_max: # Find down.
                    upper = mid_i
                else: # Find one peak.
                    return [max_i, max_j]

        return [-1, -1] # Not found.
