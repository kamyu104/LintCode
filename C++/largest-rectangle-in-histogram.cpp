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
        int i = 0;
        
        while (i <= height.size()) { // "i == height.size()" is to handle remaning heights in stack.
            if (increasing_height.empty() ||
                (i < height.size() && height[i] > height[increasing_height.top()])) {
                // Stores height in a strictly increasing order.
                increasing_height.push(i);
                ++i;
            } else {
                // Compute all largest rectangles of heights in stack which height >= current height.
                int last = increasing_height.top();
                increasing_height.pop();
                if (increasing_height.empty()) {
                    // Left bound: 0
                    // Right bound: i - 1
                    // Height: height[last]
                    max_area = max(max_area, height[last] * (i - 1 - (-1)));
                } else {
                    // Left bound: increasing_height.top() + 1
                    // Right bound: i - 1
                    // Height: height[last]
                    max_area = max(max_area, height[last] * (i - 1 - increasing_height.top()));
                }
            }
        }
        
        return max_area;
    }
};
