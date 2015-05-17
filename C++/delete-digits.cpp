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
        const auto len = A.size();
        
        // Handle boundary case
        if (len == k) {
            return "0";
        }
        
        // If a digit is greater than next one, delete it.
        stack<char> s;
        for (auto i = 0; i < len; ++i) {
            while (k > 0 && !s.empty() && s.top() > A[i]) {
                s.pop();
                --k;
            }
            s.emplace(A[i]);
        }
        
        // If all digits are increasingly sorted, delete last.
        while (k > 0) {
            s.pop();
            --k;
        }
        
        // Assemble the answer in reverse order
        string ans;
        while (!s.empty()) {
            ans.emplace_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        
        // Strip all leading '0'
        auto i = 0;
        for (; i < ans.length() && ans[i] == '0'; ++i);
        ans = ans.substr(i);
        
        // Handle boundary case
        if (ans.length() == 0) {
            return "0";
        }
        
        return ans;
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
        const auto len = A.size();
        
        // Handle boundary case
        if (len == k) {
            return "0";
        }
        
        // If a digit is greater than next one, delete it.
        int i = 0;
        while (i + 1 <= len && k > 0) {
            if (A[i] > A[i + 1]) {
                A.erase(A.begin() + i); // Not efficient, linear time
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
        if (A.length() > 0 && A[0] == '0') {
            size_t pos = A.find_first_not_of("0");
            if (pos != string::npos) {
                A = A.substr(A.find_first_not_of("0"));
            }
        }
        
        // Handle boundary case
        if (A.length() == 0) {
            return "0";
        }
        
        return A;
    }
};


