// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param A: An integer array.
     * @return: void
     */
    void rerange(vector<int> &A) {
        int n = A.size();

        // by default, start with negative in output array
        int expectPostive = false;
        int postiveCount = 0;
        for (const auto& k : A)  {
            postiveCount += k > 0? 1 : 0;
        }

        // if there are more postive than negative, start with postive
        if (2 * postiveCount > n) {
            expectPostive = true;
        }

        int pos = 0, neg = 0;
        int i = 0;

        while (pos < n && neg < n) {
            // A[pos] is the next negative
            while (pos < n && A[pos] > 0) {
                ++pos;
            }
            // A[pos] is the next postive
            while (neg < n && A[neg] < 0) {
                ++neg;
            }

            if (expectPostive && A[i] < 0) {
                swap(A[i], A[neg]);
            }

            if (!expectPostive && A[i] > 0) {
                swap(A[i], A[pos]);
            }

            if (i == pos) {
                ++pos;
            }
            if (i == neg) {
                ++neg;
            }

            expectPostive = !expectPostive;
            ++i;
        }
    }
};
