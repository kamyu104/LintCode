// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        if(heights.empty()) {
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
