// Time:  O(logn) = O(1)
// Space: O(1)

class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        int cnt = 0, multiplier = 1, left_part = n;

        while (left_part > 0) {
            // split number into: left_part, curr, right_part
            int curr = left_part % 10;
            int right_part = n % multiplier;

            // count of (c000 ~ oooc000) = (ooo + (k < curr)? 1 : 0) * 1000
            cnt += (left_part / 10 + (k < curr)) * multiplier;

            // if k == 0, oooc000 = (ooo - 1) * 1000
            if (k == 0 && multiplier > 1) {
                cnt -= multiplier;
            }

            // count of (oook000 ~ oookxxx): count += xxx + 1
            if (curr == k) {
                cnt += right_part + 1;
            }

            left_part /= 10;
            multiplier *= 10;
        }

        return cnt;
    }
};

// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        int cnt = 0;
        for (int i = 0; i <= n; ++i) {
            int num = i;
            while (num > 0) {
                if (num % 10 == k) {
                    ++cnt;
                }
                num /= 10;
            }
        }
        return cnt;
    }
};
