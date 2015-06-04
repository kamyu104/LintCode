// Time:  O(n)
// Space: O(1)

// Two pointer solution
class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        if (heights.empty()) {
            return 0;
        }

        int i = 0, j = heights.size() - 1;
        int left_height = heights[0];
        int right_height = heights[heights.size() - 1];
        int trap = 0;

        while (i < j) {
            if (left_height < right_height) {
                ++i;
                // Fill in the gap.
                trap += max(0, left_height - heights[i]);
                // Update current max height from left.
                left_height = max(left_height, heights[i]);
            }
            else {
                --j;
                // Fill in the gap.
                trap += max(0, right_height - heights[j]);
                // Update current max height from right.
                right_height = max(right_height, heights[j]);
            }
        }

        return trap;
    }
};

// Two pass scan solution
class Solution2 {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        int trap = 0;

        // Find the top.
        int top = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (heights[top] < heights[i]) {
                top = i;
            }
        }

        // Count trapped water in the left of top.
        int left_second_top = 0;
        for (int i = 0; i < top; ++i) {
            if (heights[left_second_top] < heights[i]) {
                left_second_top = i;
            }
            trap += heights[left_second_top] - heights[i];
        }

        // Count trapped water in the right of top.
        int right_second_top = heights.size() - 1;
        for (int i = heights.size() - 1; i > top; --i) {
            if (heights[right_second_top] < heights[i]) {
                right_second_top = i;
            }
            trap += heights[right_second_top] - heights[i];
        }

        return trap;
    }
};
