// Time:  O(max(m, n) * log(min(m, n)))
// Space: O(1)

class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        if (A.size() > B.size()) {
            return smallestDifference(B, A);
        }
        sort(A.begin(), A.end());

        int min_diff = numeric_limits<int>::max();
        for (const auto& b : B) {
            auto it = lower_bound(A.cbegin(), A.cend(), b);
            if (it != A.cend()) {
                min_diff = min(min_diff, *it - b);
            }
            if (it != A.cbegin()) {
                --it;
                min_diff = min(min_diff, b - *it);
            }
        }

        return min_diff;
    }
};

// Time:  O(nlogn)
// Space: O(1)
class Solution2 {
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
        int min_diff = numeric_limits<int>::max();

        while (i < A.size() && j < B.size()) {
            min_diff = min(min_diff, abs(A[i] - B[j]));
            A[i] < B[j] ? ++i : ++j;
        }

        return min_diff;
    }
};

