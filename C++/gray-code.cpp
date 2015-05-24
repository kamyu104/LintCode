// Time:  (2^n)
// Space: O(1)
// Proof of closed form formula could be found here:
// http://math.stackexchange.com/questions/425894/proof-of-closed-form-formula-to-convert-a-binary-number-to-its-gray-code
class Solution2 {
public:
    /**
     * @param n a number
     * @return Gray code
     */
    vector<int> grayCode(int n) {
        vector<int> result;
        for (int i = 0; i < 1 << n; ++i) {
            result.emplace_back(i >> 1 ^ i);
        }
        return result;
    }
};
