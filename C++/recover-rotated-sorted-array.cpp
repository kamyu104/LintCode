// Time:  O(n)
// Space: O(1)

class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        int i = findMinPoint(nums);
        reverse(nums.begin(), nums.begin() + i);
        reverse(nums.begin() + i, nums.end());
        reverse(nums.begin(), nums.end());
    }


    int findMinPoint(vector<int> &num) {
        int left = 0;
        int right = num.size() - 1;

        // Find min left s.t. num[left] > num[left + 1].
        while (left < right && num[left] >= num[right]) {
            int mid = left + (right - left) / 2;
            if (num[mid] < num[left]) {
                right = mid;
            } else if (num[mid] > num[left]) {
                left = mid + 1;
            } else {
                ++left;
            }
        }

        return left;
    }
};
