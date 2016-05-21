// Time:  O(n^2)
// Space: O(1)

// Two Pointers solution.
class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        sort(S.begin(), S.end());
        const int n = S.size();

        int count = 0;
        for (int k = 2; k < n; ++k) {
            int i = 0, j = k - 1;
            while (i < j) {  // Two Pointers, linear time.
                if (S[i] + S[j] <= S[k]) {
                    ++i;
                } else {
                    count += j - i;
                    --j;
                }
            }
        }

        return count;
    }
};

// Time:  O(n^2)
// Space: O(1)
class Solution2 {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        sort(S.begin(), S.end());
        const int n = S.size();

        int count = 0;

        for (int i = 0; i < n - 2; ++i) {
            int k = i + 2;
            for (int j = i + 1; j < n; ++j) {
                while (k < n && S[i] + S[j] > S[k]) {
                    ++k;
                }
                count += k - j - 1;
            }
        }
        return count;
    }
};
