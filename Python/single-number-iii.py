# Time:  O(n)
# Space: O(1)
#
# Given 2*n + 2 numbers, every numbers occurs twice except two, find them.
#
# Example
# Given [1,2,2,3,4,4,5,3] return 1 and 5
#
# Challenge
# O(n) time, O(1) extra space.
#

class Solution:
    """
    @param A : An integer array
    @return : Two integer
    """
    def singleNumberIII(self, A):
        # write your code here
        x_xor_y = 0
        for i in A:
            x_xor_y ^= i
        bit = x_xor_y & ~(x_xor_y - 1)
        
        x = 0
        A_x = (i for i in A if i & bit)
        for i in A_x:
            x ^= i
        
        return [x, x_xor_y ^ x]
