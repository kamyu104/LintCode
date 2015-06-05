// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // Count the number of spaces.
        int space_count = 0;
        for (int i = 0; i < length; ++i) {
            if (string[i] == ' ') {
                ++space_count;
            }
        }

        // Repalce space with "%20" in-place.
        const int new_length = length + 2 * space_count;
        for (int i = length - 1, j = new_length - 1; i >= 0; --i) {
            if (string[i] == ' ') {
                string[j--] = '0';
                string[j--] = '2';
                string[j--] = '%';
            } else {
                string[j--] = string[i];
            }
        }

        return new_length;
    }
};
