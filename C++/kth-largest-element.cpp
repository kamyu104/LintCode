// Time:  O(n) ~ O(n^2)
// Space: O(1)

class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        int left = 0, right = nums.size() - 1;
        default_random_engine gen((random_device())());
        while (left <= right) {
            // Generates a random int in [left, right].
            uniform_int_distribution<int> dis(left, right);
            int pivot_idx = dis(gen);
            int new_pivot_idx = PartitionAroundPivot(left, right, pivot_idx, nums);
            if (new_pivot_idx == k - 1) {
                return nums[new_pivot_idx];
            } else if (new_pivot_idx > k - 1) {
                right = new_pivot_idx - 1;
            } else {  // new_pivot_idx < k - 1.
                left = new_pivot_idx + 1;
            }
        }
    }

    // Partition nums[left : right] around pivot_idx, returns the new index of the
    // pivot, new_pivot_idx, after partition. After partitioning,
    // nums[left : new_pivot_idx - 1] contains elements that are greater than the
    // pivot, and nums[new_pivot_idx + 1 : right] contains elements that are less
    // than the pivot.
    int PartitionAroundPivot(int left, int right, int pivot_idx, vector<int>& nums) {
        int pivot_value = nums[pivot_idx];
        int new_pivot_idx = left;
        swap(nums[pivot_idx], nums[right]);
        for (int i = left; i < right; ++i) {
            if (nums[i] > pivot_value) {
                swap(nums[i], nums[new_pivot_idx++]);
            }
        }
        swap(nums[right], nums[new_pivot_idx]);
        return new_pivot_idx;
    }
};

class Solution2 {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        return nums[k - 1];
    }
};
