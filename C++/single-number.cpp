// Time:  O(n)
// Space: O(1)

class Solution {
public:
	/**
	 * @param A: Array of integers.
	 * return: The single number.
	 */
    int singleNumber(vector<int> &A) {
        return accumulate(A.cbegin(), A.cend(), 0, std::bit_xor<int>());
    }
};

class Solution2 {
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
