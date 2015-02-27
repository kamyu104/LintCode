# Time:  O(n*m)
# Space: O(m)
#
# Given n items with size A[i], an integer m denotes the size of a backpack. 
# How full you can fill this backpack? 
#
# Note
# You can not divide any item into small pieces.
#
# Example
# If we have 4 items with size [2, 3, 5, 7], the backpack size is 11, we can select 2, 3 and 5, 
# so that the max size we can fill this backpack is 10. If the backpack size is 12. 
# we can select [2, 3, 7] so that we can fulfill the backpack.
#
# You function should return the max size we can fill in the given backpack.
#
class Solution:
    # @param m: An integer m denotes the size of a backpack
    # @param A: Given n items with size A[i]
    # @return: The maximum size
    def backPack(self, m, A):
        # write your code here
        d = [[False for j in xrange(m+1)] for i in xrange(2)]
        result = 0
        d[0][0] = True 
        
        for i in xrange(1, len(A) + 1):
            d[i%2][0] = True 
            for j in xrange(1, m+1):
                d[i%2][j] = d[(i-1)%2][j]
                if j >= A[i-1]:
                    d[i%2][j] = d[(i-1)%2][j] or d[(i-1)%2][j-A[i-1]]
                if d[i%2][j]:
                    result = max(result, j)
                    
        return result
