// Time:  O(m * n * l), l is length of the word
// Space: O(l)

class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char>> &board, string word) {
        unordered_set<string> ret;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        int cur = 0;

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (wordSearchDFS(board, visited, word, i, j, cur)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool wordSearchDFS(vector<vector<char>> &grid,
                       vector<vector<bool>> &visited,
                       string word,
                       int i,
                       int j,
                       int cur) {
        // Invalid state.
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return false;
        }

        // Not mathced or visited.
        if (grid[i][j] != word[cur] || visited[i][j]) {
            return false;
        }

        // Update current string.
        ++cur;

        // Find the string, add to the answers.
        if (cur == word.length()) {
            return true;
        }

        // Marked as visited.
        visited[i][j] = true;

        // Try each direction.
        const vector<pair<int, int>> directions{{0, -1}, {0, 1},
                                                {-1, 0}, {1, 0}};
        for (const auto& d : directions) {
            if (wordSearchDFS(grid, visited, word,
                              i + d.first, j + d.second, cur)) {
                return true;
            }
        }

        visited[i][j] = false;

        return false;
    }
};
