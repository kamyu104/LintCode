// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int i = 0;
        int j = 0;
        int min_diff = INT_MAX;

        while (i < A.size() && j < B.size()) {
            min_diff = min(min_diff, abs(A[i] - B[j]));
            A[i] < B[j] ? ++i : ++j;
        }

        return min_diff;
    }
};

