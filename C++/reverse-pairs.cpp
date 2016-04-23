// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    /**
     * @param A an array
     * @return total of reverse pairs
     */
    long long reversePairs(vector<int>& A) {
        int count = 0;
        vector<pair<int, int>> num_idxs;
        for (int i = 0; i < A.size(); ++i) {
            num_idxs.emplace_back(A[i], i);
        }
        countAndMergeSort(&num_idxs, 0, num_idxs.size() - 1, &count);
        return count;
    }

    void countAndMergeSort(vector<pair<int, int>> *num_idxs, int start, int end, int *count) {
        if (end - start <= 0) {  // The number of range [start, end] of which size is less than 2 doesn't need sort.
            return;
        }
        int mid = start + (end - start) / 2;
        countAndMergeSort(num_idxs, start, mid, count);
        countAndMergeSort(num_idxs, mid + 1, end, count);

        int l = start;
        vector<pair<int, int>> tmp;
        for (int i = mid + 1; i <= end; ++i) {
            // Merge the two sorted arrays into tmp.
            while (l <= mid && (*num_idxs)[l].first <= (*num_idxs)[i].first) {
                tmp.emplace_back((*num_idxs)[l++]);
            }
            tmp.emplace_back((*num_idxs)[i]);
            *count += mid - l + 1;
        }
        while (l <= mid) {
            tmp.emplace_back((*num_idxs)[l++]);
        }
        // Copy tmp back to num_idxs.
        copy(tmp.begin(), tmp.end(), num_idxs->begin() + start);
    }
};
