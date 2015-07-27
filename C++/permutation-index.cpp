// Time:  O(n^2)
// Space: O(1)

class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        long long index = 1;
        // Position 1 is paired with factor 0 and so is skipped.
        int position = 2;
        long long factor = 1;
        for (int i = static_cast<int>(A.size()) - 2; i >= 0; --i) {
            int successors = 0;
            for (int j = i + 1; j < A.size(); ++j) {
                if (A[i] > A[j]) {
                    ++successors;
                }
            }
            index += successors * factor;
            factor *= position;
            ++position;
        }
        return index;
    }
};
