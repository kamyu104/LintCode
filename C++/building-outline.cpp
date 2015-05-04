// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    enum {start, end, height};
    /**
     * @param buildings: A list of lists of integers
     * @return: Find the outline of those buildings
     */
    vector<vector<int> > buildingOutline(vector<vector<int> > &buildings) {
        return ComputeSkylineInInterval(buildings, 0, buildings.size());
    }
    
    // Divide and Conquer.
    vector<vector<int>> ComputeSkylineInInterval(const vector<vector<int>>& buildings,
                                                 int left_endpoint, int right_endpoint) {
        if (right_endpoint - left_endpoint <= 1) {  // 0 or 1 skyline, just copy it.
            return {buildings.cbegin() + left_endpoint,
                buildings.cbegin() + right_endpoint};
        }
        int mid = left_endpoint + ((right_endpoint - left_endpoint) / 2);
        auto left_skyline = ComputeSkylineInInterval(buildings, left_endpoint, mid);
        auto right_skyline = ComputeSkylineInInterval(buildings, mid, right_endpoint);
        return MergeSkylines(left_skyline, right_skyline);
    }
    
    // Merge Sort
    vector<vector<int>> MergeSkylines(vector<vector<int>>& left_skyline, vector<vector<int>>& right_skyline) {
        int i = 0, j = 0;
        vector<vector<int>> merged;
        
        while (i < left_skyline.size() && j < right_skyline.size()) {
            if (left_skyline[i][end] < right_skyline[j][start]) {
                merged.emplace_back(left_skyline[i++]);
            } else if (right_skyline[j][end] < left_skyline[i][start]) {
                merged.emplace_back(right_skyline[j++]);
            } else if (left_skyline[i][start] <= right_skyline[j][start]) {
                MergeIntersectSkylines(merged, left_skyline[i], i,
                                       right_skyline[j], j);
            } else {  // left_skyline[i][start] > right_skyline[j][start].
                MergeIntersectSkylines(merged, right_skyline[j], j,
                                       left_skyline[i], i);
            }
        }
        
        // Insert the remaining skylines.
        merged.insert(merged.end(), left_skyline.begin() + i, left_skyline.end());
        merged.insert(merged.end(), right_skyline.begin() + j, right_skyline.end());
        return merged;
    }
    
    // a[start] <= b[start]
    void MergeIntersectSkylines(vector<vector<int>>& merged, vector<int>& a, int& a_idx,
                                vector<int>& b, int& b_idx) {
        if (a[end] <= b[end]) {
            if (a[height] > b[height]) {  // |aaa|
                if (b[end] != a[end]) {   // |abb|b
                    merged.emplace_back(a), ++a_idx;
                    b[start] = a[end];
                } else {        // aaa
                    ++b_idx;    // abb
                }
            } else if (a[height] == b[height]) { // abb
                b[start] = a[start], ++a_idx;    // abb
            } else {  // a[height] < b[height].
                if (a[start] != b[start]) {                                           //    bb
                    merged.emplace_back(vector<int>{a[start], b[start], a[height]});  // |a|bb
                }
                ++a_idx;
            }
        } else {  // a[end] > b[end].
            if (a[height] >= b[height]) {  // aaaa
                ++b_idx;                   // abba
            } else {
                //    |bb|
                // |a||bb|a
                if (a[start] != b[start]) {
                    merged.emplace_back(vector<int>{a[start], b[start], a[height]});
                }
                a[start] = b[end];
                merged.emplace_back(b), ++b_idx;
            }
        }
    }
};
