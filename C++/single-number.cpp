// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param A: Array of integers.
     * return: The single number.
     */
    int singleNumber(vector<int> &A) {
        int single = 0;
        for (const auto& i : A) {
            single ^= i;
        }

        return single;
    }
};
