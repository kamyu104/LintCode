// Time:  O(n)
// Space: O(n)

class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        if (nums.size() < 2) {
            return vector<long long>();
        }
        
        vector<long long> left_product(nums.size());
        vector<long long> right_product(nums.size());
        vector<long long> product(nums.size());
        
        left_product[0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            left_product[i] = left_product[i - 1] * nums[i - 1];
        }
        
        right_product[nums.size() - 1] = 1;
        for (int j = nums.size() - 2; j >= 0; --j) {
            right_product[j] = right_product[j + 1] * nums[j + 1];
        }
        
        for (int k = 0; k < nums.size(); ++k) {
            product[k] = left_product[k] * right_product[k];
        }
        
        return product;
    }
};
