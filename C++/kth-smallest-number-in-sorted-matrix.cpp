// Time:  O(k * log(min(n, m)))
// Space: O(k)

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        multimap<int, pair<int, int>> min_bst;
        int kth_smallest = 0;
        
        // Find min number of height and width
        if (true || matrix.size() < matrix[0].size()) {
            // Init BST by the first element of each row.
            for (int i = 0; i < matrix.size(); ++i) {
                min_bst.emplace(move(pair<int, pair<int, int>>{matrix[i][0], {i, 0}}));
            }
            
            while (k--) {
                // Pop the min of BST.
                kth_smallest = min_bst.cbegin()->first;
                int i = min_bst.cbegin()->second.first;
                int j = min_bst.cbegin()->second.second;
                min_bst.erase(min_bst.cbegin());
                
                // Insert the next possible element.
                if (j + 1 < matrix[i].size()) {
                    min_bst.emplace(move(pair<int, pair<int, int>>{matrix[i][j + 1], {i, j + 1}}));
                }
            }
        } else {
            // Init BST by the first element of each column.
            for (int j = 0; j < matrix[0].size(); ++j) {
                min_bst.emplace(move(pair<int, pair<int, int>>{matrix[0][j], {0, j}}));
            }
            
            while (k--) {
                // Pop the min of BST.
                kth_smallest = min_bst.cbegin()->first;
                int i = min_bst.cbegin()->second.first;
                int j = min_bst.cbegin()->second.second;
                min_bst.erase(min_bst.cbegin());
                
                // Insert the next possible element.
                if (i + 1 < matrix.size()) {
                    min_bst.emplace(move(pair<int, pair<int, int>>{matrix[i + 1][j], {i + 1, j}}));
                }
            }
        }
        
        return kth_smallest;
    }
};
