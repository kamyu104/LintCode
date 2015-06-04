// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        // Reverse the whole string first.
        reverse(s.begin(), s.end());

        size_t start = 0, end;
        while ((end = s.find(" ", start)) != string::npos) {
            // Reverse each word in the string.
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
        }
        // Reverse the last word.
        reverse(s.begin() + start, s.end());

        // Remove beginning blank.
        if ((start = s.find_first_not_of(" ")) != string::npos) {
            return s.substr(start);
        }

        return s;
    }
};
