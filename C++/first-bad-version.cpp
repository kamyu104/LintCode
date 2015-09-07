// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        int left = 1 - 1, right = n + 1;

        // At the last, left is not target, right is target.
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            // Is target
            if (VersionControl::isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right;
    }
};

class Solution2 {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        int left = 1, right = n + 1;

        // At the last, left is not sure for target, right is target.
        while (left < right) {
            int mid = left + (right - left) / 2;
            // Is target
            if (VersionControl::isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

class Solution3 {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        int left = 1, right = n;

        // At the last, left is not sure for target, right is not sure for target.
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // Is target
            if (VersionControl::isBadVersion(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
