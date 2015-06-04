// Time:  O(n * n!)
// Space: O(n)

class Solution {
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    vector<vector<string>> solveNQueens(int n) {
        vector<int> placement(n);
        vector<vector<string>> result;
        NQueensHelper(n, 0, &placement, &result);
        return result;
    }

    void NQueensHelper(int n, int row, vector<int>* col_placement,
                       vector<vector<string>>* result) {
        if (row == n) {
            result->emplace_back(CreateOutput(*col_placement));
        } else {
            for (int col = 0; col < n; ++col) {
                (*col_placement)[row] = col;
                if (IsFeasible(*col_placement, row)) {
                    NQueensHelper(n, row + 1, col_placement, result);
                }
            }
        }
    }

    vector<string> CreateOutput(const vector<int>& col_placement) {
        vector<string> sol;
        for (int row : col_placement) {
            string line(col_placement.size(), '.');
            line[row] = 'Q';
            sol.emplace_back(line);
        }
        return sol;
    }

    bool IsFeasible(const vector<int>& col_placement, int row) {
        for (int i = 0; i < row; ++i) {
            int diff = abs(col_placement[i] - col_placement[row]);
            if (diff == 0 || diff == row - i) {
                return false;
            }
        }
        return true;
    }
};



