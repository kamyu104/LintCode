// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        int i = 0, j = heights.size() - 1, max_area = 0;
        while (i < j) {
            max_area = max(max_area, min(heights[i], heights[j]) * (j - i));
            if (heights[i] > heights[j]) {
                --j;
            } else if (heights[i] < heights[j]) {
                ++i;
            } else {  // heights[i] == heights[j].
                ++i, --j;
            }
        }
        return max_area;
    }
};

