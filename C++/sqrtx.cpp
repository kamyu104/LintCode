// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        int left = 1;
        int right = x / 2;

        // Find min of left s.t. left > x / left.
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid > x / mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left - 1;
    }
};

class Solution2 {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        int left = 1;
        int right = x / 2 + 1;

        // Find min of left s.t. left > x / left.
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid > x / mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left - 1;
    }
};

class Solution3 {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        int left = 0;
        int right = x / 2 + 1;

        // Find min of right s.t. right > x / right.
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            if (mid > x / mid) {
                right = mid;
            } else {
                left = mid;
            }
        }

        return right - 1;
    }
};

