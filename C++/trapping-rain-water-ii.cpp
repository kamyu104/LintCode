// Time:  O(n^2 * logn)
// Space: O(n^2)

// BFS with priority queue (min heap), refactored version.
class Solution {
public:
    struct Cell {
        int i;
        int j;
        int height;
    };
    
    struct Compare {
        bool operator()(const Cell& a, const Cell& b) {
            return a.height > b.height;
        }
    };
    
    /**
     * @param heights: a matrix of integers
     * @return: an integer
     */
    int trapRainWater(vector<vector<int> > &heights) {
        // Init m, n, trap.
        m = heights.size();
        n = heights[0].size();
        trap = 0;
        is_visited = vector<vector<bool>>(m, vector<bool>(n, false));
        
        // Put the cell on the border into heap.
        for (int i = 0; i < m; ++i) {
            heap.emplace(Cell{i, 0, heights[i][0]});
            heap.emplace(Cell{i, n - 1, heights[i][n - 1]});
        }
        for (int j = 0; j < n; ++j) {
            heap.emplace(Cell{0, j, heights[0][j]});
            heap.emplace(Cell{m - 1, j, heights[m - 1][j]});
        }
        
        // BFS
        while(!heap.empty()) {
            Cell c = heap.top();
            heap.pop();
            is_visited[c.i][c.j] = true;
            
            check(heights, c.i + 1, c.j, c.height); // Up
            check(heights, c.i - 1, c.j, c.height); // Down
            check(heights, c.i, c.j + 1, c.height); // Right
            check(heights, c.i, c.j - 1, c.height); // Left
        }
        
        return trap;
    }
    
    void check(vector<vector<int>>& heights, int i, int j, int height) {
        if ( i < 0 || i >= m || j < 0 || j >= n) {
            return;
        }
        
        if (!is_visited[i][j]) {
            is_visited[i][j] = true; // Mark as visited.
            trap += max(0, height - heights[i][j]); // Fill in the gap.
            heap.emplace(Cell{i, j, max(height, heights[i][j])});
        }
    }
    
private:
    int m;
    int n;
    int trap;
    vector<vector<bool>> is_visited;
    priority_queue<Cell ,vector<Cell>, Compare> heap; // Use min heap to get the lowerest cell.
};

// Time:  O(n^2 * logn)
// Space: O(n^2)

// BFS with priority queue (min heap)
class Solution2 {
public:
    struct Cell {
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
        
        // Use min heap to get the lowerest Cell.
        auto comp = [](Cell a, Cell b ) { return a.height > b.height; };
        priority_queue<Cell , vector<Cell>, decltype(comp)> heap(comp);
        
        // Put the Cells on the border into min heap.
        for (int i = 0; i < m; ++i) {
            heap.emplace(Cell{i, 0, heights[i][0]});
            heap.emplace(Cell{i, n - 1, heights[i][n - 1]});
        }
        for (int j = 0; j < n; ++j) {
            heap.emplace(Cell{0, j, heights[0][j]});
            heap.emplace(Cell{m - 1, j, heights[m - 1][j]});
        }
        
        // BFS with priority queue (min heap)
        while(!heap.empty()) {
            // Get the lowest Cell.
            Cell c = heap.top();
            heap.pop();
            is_visited[c.i][c.j] = true;
            
            // Up
            if (c.i + 1 < m && !is_visited[c.i + 1][c.j]) {
                is_visited[c.i + 1][c.j] = true;
                trap += max(0, c.height - heights[c.i + 1][c.j]); // Fill in the gap.
                heap.emplace(Cell{c.i + 1, c.j, max(c.height,
                                                    heights[c.i + 1][c.j])});
            }
            // Down
            if (c.i - 1 >= 0 && !is_visited[c.i - 1][c.j]) {
                is_visited[c.i - 1][c.j] = true;
                trap += max(0, c.height - heights[c.i - 1][c.j]); // Fill in the gap.
                heap.emplace(Cell{c.i - 1, c.j, max(c.height,
                                                    heights[c.i - 1][c.j])});
            }
            // Right
            if (c.j + 1 < n && !is_visited[c.i][c.j + 1]) {
                is_visited[c.i][c.j + 1] = true;
                trap += max(0, c.height - heights[c.i][c.j + 1]); // Fill in the gap.
                heap.emplace(Cell{c.i, c.j + 1, max(c.height,
                                                    heights[c.i][c.j + 1])});
            }
            // Left
            if (c.j - 1 >= 0 && !is_visited[c.i][c.j - 1]) {
                is_visited[c.i][c.j - 1] = true;
                trap += max(0, c.height - heights[c.i][c.j - 1]); // Fill in the gap.
                heap.emplace(Cell{c.i, c.j - 1, max(c.height,
                                                    heights[c.i][c.j - 1])});
            }
        }
        
        return trap;
    }
};
