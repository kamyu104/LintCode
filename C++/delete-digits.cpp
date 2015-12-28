// Time:  O(n)
// Space: O(n)
//
// Given string A representative a positive integer which has N digits,
// remove any k digits of the number, the remaining digits are arranged
// according to the original order to become a new positive integer.
// Make this new positive integers as small as possible.
//
// N <= 240 and k <= N,
//
// Example
// Given an integer A="178542", k=4
//
// return a string "12"
//

class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        // If a digit is greater than next one, delete it.
        string s;
        for (const auto c : A) {
            while (k > 0 && !s.empty() && s.back() > c) {
                s.pop_back();
                --k;
            }
            s.push_back(c);
        }

        // If all digits are increasingly sorted, delete last.
        s.resize(s.length() - k);

        // Strip all leading '0'
        return s.empty() ? "0" : s.substr(s.find_first_not_of('0'));
    }
};

// Time:  O(k * n)
// Space: O(1)
// Greedy method
class Solution2 {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        // If a digit is greater than next one, delete it.
        for (int i = 0; i + 1 <= A.size() && k > 0;) {
            if (A[i] > A[i + 1]) {
                A.erase(A.begin() + i); // Not efficient, linear time
                i = max(0, i - 1);
                --k;
            } else {
                ++i;
            }
        }

        // If all digits are increasingly sorted, delete last.
        A.resize(A.length() - k);

        // Strip all leading '0'
        return A.empty() ? "0" : A.substr(A.find_first_not_of('0'));
    }
};


