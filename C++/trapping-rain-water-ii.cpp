// Time:  O(n^2 * logn)
// Space: O(n^2)

// BFS with priority queue (min heap)
class Solution {
public:
    struct cell {
        int i;
        int j;
        int height;
    };
    
    /**
     * @param heights: a matrix of integers
     * @return: an integer
     */
    int trapRainWater(vector<vector<int> > &heights) {
        int m = heights.size();
        int n = heights[0].size();
        int trap = 0;
        vector<vector<bool>> is_visited(m, vector<bool>(n, false));
        
        // Use min heap to get the lowerest cell.
        auto comp = [](cell a, cell b ) { return a.height > b.height; };
        priority_queue<cell , vector<cell>, decltype(comp)> heap(comp);
        
        // Put the cells on the border into min heap.
        for (int i = 0; i < m; ++i) {
            heap.emplace(cell{i, 0, heights[i][0]});
            heap.emplace(cell{i, n - 1, heights[i][n - 1]});
        }
        for (int j = 0; j < n; ++j) {
            heap.emplace(cell{0, j, heights[0][j]});
            heap.emplace(cell{m - 1, j, heights[m - 1][j]});
        }
        
        // BFS with priority queue (min heap)
        while(!heap.empty()) {
            cell c = heap.top();
            heap.pop();
            is_visited[c.i][c.j] = true;
            
            // Up
            if (c.i + 1 < m && !is_visited[c.i + 1][c.j]) {
                is_visited[c.i + 1][c.j] = true;
                trap += max(0, c.height - heights[c.i + 1][c.j]);
                heap.emplace(cell{c.i + 1, c.j, max(c.height,
                                                    heights[c.i + 1][c.j])});
            }
            // Down
            if (c.i - 1 >= 0 && !is_visited[c.i - 1][c.j]) {
                is_visited[c.i - 1][c.j] = true;
                trap += max(0, c.height - heights[c.i - 1][c.j]);
                heap.emplace(cell{c.i - 1, c.j, max(c.height,
                                                    heights[c.i - 1][c.j])});
            }
            // Right
            if (c.j + 1 < n && !is_visited[c.i][c.j + 1]) {
                is_visited[c.i][c.j + 1] = true;
                trap += max(0, c.height - heights[c.i][c.j + 1]);
                heap.emplace(cell{c.i, c.j + 1, max(c.height,
                                                    heights[c.i][c.j + 1])});
            }
            // Left
            if (c.j - 1 >= 0 && !is_visited[c.i][c.j - 1]) {
                is_visited[c.i][c.j - 1] = true;
                trap += max(0, c.height - heights[c.i][c.j - 1]);
                heap.emplace(cell{c.i, c.j - 1, max(c.height,
                                                    heights[c.i][c.j - 1])});
            }
        }
        
        return trap;
    }
};
