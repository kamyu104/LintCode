# Time:  O(logn)
# Space: O(1)
#
# There is an integer array which has the following features:
#
#  * The numbers in adjacent positions are different.
#
#  * A[0] < A[1] && A[A.length - 2] > A[A.length - 1].
# 
# We define a position P is a peek if A[P] > A[P-1] && A[P] > A[P+1].
#
# Find a peak element in this array. Return the index of the peak.
#
# Note
# The array may contains multiple peeks, find any of them.
# 
# Example
# [1, 2, 1, 3, 4, 5, 7, 6]
#
# return index 1 (which is number 2)  or 6 (which is number 7)
#
# Challenge
# Time complexity O(logN)
#

class Solution:
    #@param A: An integers list.
    #@return: return any of peek positions.
    def findPeak(self, A):
        low, high = 0, len(A) - 1
        
        while low < high:
            mid = low + (high - low) / 2
            if (mid == 0 or A[mid - 1] <= A[mid]) and \
               (mid == len(A) - 1 or A[mid + 1] <= A[mid]):
                return mid
            elif mid > 0 and A[mid - 1] > A[mid]:
                high = mid - 1
            else:
                low = mid + 1
            mid = low + (high - low) / 2
       
        return low
