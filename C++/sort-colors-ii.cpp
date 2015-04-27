// Time:  O(n)
// Space: O(1)

// Inplace counting sort.
class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    void sortColors2(vector<int> &colors, int k) {
        for(int i = 0; i < colors.size(); ++i) {
            if (colors[i] > 0) {
                int pos = colors[i] - 1;
                if (colors[pos] <= 0) { // Bucket exists.
                    --colors[pos];
                    colors[i] = 0;
                }
                else { // Init a new bucket.
                    colors[i] = colors[pos];
                    colors[pos] = -1;
                    --i;
                }
            }
        }
        
        int i = colors.size() - 1;
        for (int j = k - 1;j >= 0; --j) {
            while(colors[j] < 0) { // Reorder the color by count of each bucket.
                ++colors[j];
                colors[i--] = j + 1;
            }
        }
    }
};
