// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        int left = 0;
        int right = num.size() - 1;

        // Find min left s.t. num[left] < num[left'].
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

        return num[left];
    }
};

