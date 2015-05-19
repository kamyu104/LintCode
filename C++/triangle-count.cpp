// Time:  O(n^3)
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
        
        for (int i = 0; i < n-2; ++i) {
            // Initialize index of the rightmost third element
            int k = i + 2;
            
            // Fix the second element
            for (int j = i+1; j < n; ++j) {
                while (k < n && S[i] + S[j] > S[k]) {
                    ++k;
                }
                count += k - j - 1;
            }
        }
        return count;
    }
};
