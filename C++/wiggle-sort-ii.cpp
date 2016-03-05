// Time:  O(n) ~ O(n^2), O(n) on average 
// Space: O(1)

// Tri Partition (aka Dutch National Flag Problem) with virtual index solution.
class Solution {
public:
    /**
     * @param nums a list of integer
     * @return void
     */  
    void wiggleSort(vector<int>& nums) {
        int mid = (nums.size() - 1) / 2;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());  // O(n) ~ O(n^2) time
        reversedTriPartitionWithVI(nums, nums[mid]);  // O(n) time, O(1) space
    }

    void reversedTriPartitionWithVI(vector<int>& nums, int val) {
        const int N = nums.size() / 2 * 2 + 1;
        #define Nums(i) nums[(1 + 2 * (i)) % N]
        for (int i = 0, j = 0, n = nums.size() - 1; j <= n;) {
            if (Nums(j) > val) {
                swap(Nums(i++), Nums(j++));
            } else if (Nums(j) < val) {
                swap(Nums(j), Nums(n--));
            } else {
                ++j;
            }
        }
    }
};
