# Time:  O(n)
# Space: O(1)

from math import sqrt

class Solution:
    """
    @param A: An integer array.
    @param B: An integer array.
    @return: Cosine similarity.
    """
    def cosineSimilarity(self, A, B):
        invalid = 2.0
        if len(A) != len(B):
            return invalid
        A_dot_B, A_dot_A, B_dot_B = 0.0, 0.0, 0.0
        for i in xrange(len(A)):
            A_dot_B += A[i] * B[i]
            A_dot_A += A[i] * A[i]
            B_dot_B += B[i] * B[i]
        return A_dot_B / sqrt(A_dot_A) / sqrt(B_dot_B) if A_dot_A and B_dot_B \
                                                       else invalid
