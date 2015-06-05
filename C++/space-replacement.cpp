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
        const array<char, 3> to{'%', '2', '0'};

        int space_count = 0;
        for (int i = 0; i < length; ++i) {
            if (string[i] == ' ') {
                ++space_count;
            }
        }

        const int new_length = length +
                               (static_cast<int>(to.size()) - 1) * space_count;
        for (int i = length - 1, j = new_length - 1; i >= 0; --i) {
            if (string[i] == ' ') {
                j -= to.size();
                copy(to.cbegin(), to.cend(), string + j + 1);
            } else {
                string[j--] = string[i];
            }
        }

        return new_length;
    }
};
