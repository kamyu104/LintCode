// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &array, int target) {
        int left = 0;
        int right = array.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (array[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (left < array.size() && array[left] == target) {
            return left;
        }

        return -1;
    }
};


class Solution2 {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &array, int target) {
        int left = 0;
        int right = array.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (array[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        if (left < array.size() && array[left] == target) {
            return left;
        }

        return -1;
    }
};

class Solution3 {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &array, int target) {
        int left = -1;
        int right = array.size();

        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            if (array[mid] >= target) {
                right = mid;
            } else {
                left = mid;
            }
        }

        if (right < array.size() && array[right] == target) {
            return right;
        }

        return -1;
    }
};

