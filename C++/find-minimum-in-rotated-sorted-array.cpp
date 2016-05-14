// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        int left = 0, right = num.size() - 1;
        const auto target = num.back();

        while (left <= right) {
            const auto  mid = left + (right - left) / 2;
            if (num[mid] <= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return num[left];
    }
};

class Solution2 {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        int left = 0, right = num.size() - 1;

        // Find min left s.t. num[left] < num[left'].
        while (left < right && num[left] >= num[right]) {
            const auto mid = left + (right - left) / 2;
            if (num[mid] < num[left]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return num[left];
    }
};

