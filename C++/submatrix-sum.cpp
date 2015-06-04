// Time:  O(m * n^2), where m > n
// Space: O(m)

class Solution {
public:
    /**
     * @param matrix an integer matrix
     * @return the coordinate of the left-up and right-down number
     */
    vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) {
        if (matrix.size() < matrix[0].size()) {  // Height is smaller.
            return horizontal_search(matrix);
        } else {  // Width is smaller.
            return vertical_search(matrix);
        }
    }

    vector<vector<int>> horizontal_search(const vector<vector<int>>& matrix) {
        for (int up = 0; up < matrix.size(); ++up) {
            vector<int> temp_row(matrix[0].size());
            for (int down = up; down < matrix.size(); ++down) {
                // Find sum of every mini-column between 
                // up and down rows and save it into temp_row[]
                for (int j = 0; j < matrix[0].size(); ++j) {
                    temp_row[j] += matrix[down][j];
                }

                // Find the subarray which equals to zero in temp_row[].
                const auto& left_right = subarraySum(temp_row);
                if (!left_right.empty()) {
                    return {{up, left_right[0]}, {down, left_right[1]}};
                }
            }
        }
        return {{-1, -1}, {-1, -1}};
    }

    vector<vector<int>> vertical_search(const vector<vector<int>>& matrix) {
        for (int left = 0; left < matrix[0].size(); ++left) {
            vector<int> temp_col(matrix.size());
            for (int right = left; right < matrix[0].size(); ++right) {
                // Find sum of every mini-row between 
                // left and right cols and save it into temp_col[]
                for (int i = 0; i < matrix.size(); ++i) {
                    temp_col[i] += matrix[i][right];
                }

                // Find the subarray which equals to zero in temp_col[].
                const auto& up_down = subarraySum(temp_col);
                if (!up_down.empty()) {
                    return {{up_down[0], left}, {up_down[1], right}};
                }
            }
        }
        return {{-1, -1}, {-1, -1}};
    }

    vector<int> subarraySum(const vector<int>& A) {
        unordered_map<int, int> lookup;
        lookup[0] = -1;
        for (int i = 0, sum = 0; i < A.size(); ++i) {
            sum += A[i];
            if (!lookup.emplace(sum, i).second) {  // Already exists.
                return {lookup[sum] + 1, i};
            }
        }
        return {};
    }
};
