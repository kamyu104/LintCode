// Time:  O(m * n)
// Space: O(m * n)

class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        if (grid.empty()) {
            return 0;
        }

        vector<vector<bool>> used(grid.size(),
                                  vector<bool>(grid[0].size(), false));

        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] && !used[i][j]) {
                    findIsland(grid, i, j, &used);
                    ++count;
                }
            }
        }
        return count;
    }

    void findIsland(const vector<vector<bool>>& grid,
             const int x,
             const int y,
             vector<vector<bool>> *used) {
        if (!grid[x][y] || (*used)[x][y]) {
            return;
        }
        
        (*used)[x][y] = true;
        if (x > 0) {
            findIsland(grid, x - 1, y, used);
        }
        if (x < grid.size() - 1) {
            findIsland(grid, x + 1, y, used);
        }
        if (y > 0) {
            findIsland(grid, x, y - 1, used);
        }
        if (y < grid[0].size() - 1) {
            findIsland(grid, x, y + 1, used);
        }
    }
};
