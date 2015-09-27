// Time:  O(n)
// Space: O(1)

class Solution {
  public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        const double invalid = 2.0;
        if (A.size() != B.size()) {
            return invalid;
        }

        double A_dot_B = 0.0, A_dot_A = 0.0, B_dot_B = 0.0;
        for (int i = 0; i < A.size(); ++i) {
            A_dot_B += A[i] * B[i];
            A_dot_A += A[i] * A[i];
            B_dot_B += B[i] * B[i];
        }
        return A_dot_A && B_dot_B ?
                   A_dot_B / sqrt(A_dot_A) / sqrt(B_dot_B) :
                   invalid;
    }
};
