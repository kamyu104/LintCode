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
        int curr = 0;

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (wordSearchDFS(board, visited, word, i, j, curr)) {
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
                       int curr) {
        // Invalid state.
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return false;
        }

        // Not mathced or visited.
        if (grid[i][j] != word[curr] || visited[i][j] ) {
            return false;
        }

        // Update current string.
        ++curr;

        // Find the string, add to the answers.
        if (curr == word.length()) {
            return true;
        }

        // Marked as visited.
        visited[i][j] = true;

        // Try each direction.
        vector<pair<int, int>> direction{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        for (int k = 0; k < 4; ++k) {
            if (wordSearchDFS(grid, visited, word,
                              i + direction[k].first, j + direction[k].second, curr)) {
                return true;
            }
        }

        visited[i][j] = false;

        return false;
    }
};
