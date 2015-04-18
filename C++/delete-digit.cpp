// Time:  O(kn)
// Space: O(1)
// Greedy method
class Solution {
    public:
        /**
         *@param A: A positive integer which has N digits, A is a string.
         *@param k: Remove k digits.
         *@return: A string
         */
        string DeleteDigits(string A, int k) {
            auto len = A.size();

            // Handle boundary case
            if (len == k) {
                return "0";
            }

            // If a digit is greater than next one, delete it.
            int i = 0;
            while (i + 1 <= len && k > 0) {
                if (A[i] > A[i + 1]) {
                    A.erase(A.begin() + i);
                    i = max(0, i - 1);
                    --k;
                } else {
                    ++i;
                }
            }

            // If all digits are increasingly sorted, delete last.
            if (k > 0) {
                A = A.substr(0, A.length() - k);
            }

            // Strip all leading '0' 
            while(A.length() > 0 && A[0] == '0') {
                A.erase(A.begin());
            }

            // Handle boundary case
            if (A.length() == 0) {
                return "0";
            }

            return A;
        } 
};


