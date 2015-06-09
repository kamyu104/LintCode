// Time:   O(n)
// Spacee: O(1)

class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        int left = 0, right = letters.size() - 1;

        while (left < right) {
            if (isupper(letters[left])) {
                swap(letters[left], letters[right]);
                --right;
            } else {
                ++left;
            }
        }
    }
};

