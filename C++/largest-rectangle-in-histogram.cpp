// Time:  O(n)
// Space: O(n)

class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        stack<int> increasing_height;
        int max_area = 0;

        for (int i = 0; i <= height.size();) {
            if (increasing_height.empty() ||
                (i < height.size() && height[i] > height[increasing_height.top()])) {
                increasing_height.emplace(i);
                ++i;
            } else {
                auto h = height[increasing_height.top()];
                increasing_height.pop();
                auto left = increasing_height.empty() ? -1 : increasing_height.top();
                max_area = max(max_area, h * (i - left - 1));
            }
        }

        return max_area;
    }
};
