// Time:  O(n)
// Space: O(1)

class Solution {
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
public:
    vector<long long> productExcludeItself(vector<int> &nums) {
        if (nums.empty()) {
            return {};
        }

        vector<long long> left_product(nums.size());

        left_product[0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            left_product[i] = left_product[i - 1] * nums[i - 1];
        }

        long long right_product = 1;
        for (int i = static_cast<int>(nums.size()) - 2; i >= 0; --i) {
            right_product *= nums[i + 1];
            left_product[i] = left_product[i] * right_product;
        }

        return left_product;
    }
};

// Time:  O(n)
// Space: O(n)
class Solution2 {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        if (nums.empty()) {
            return {};
        }

        vector<long long> left_product(nums.size());
        vector<long long> right_product(nums.size());
        vector<long long> product(nums.size());

        left_product[0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            left_product[i] = left_product[i - 1] * nums[i - 1];
        }

        right_product[nums.size() - 1] = 1;
        for (int j = static_cast<int>(nums.size()) - 2; j >= 0; --j) {
            right_product[j] = right_product[j + 1] * nums[j + 1];
        }

        for (int k = 0; k < nums.size(); ++k) {
            product[k] = left_product[k] * right_product[k];
        }

        return product;
    }
};
