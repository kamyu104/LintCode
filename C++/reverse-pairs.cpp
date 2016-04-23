// Time:  O(nlogn)
// Space: O(n)

// BIT solution.
class Solution {
public:
    /**
     * @param A an array
     * @return total of reverse pairs
     */
    long long reversePairs(vector<int>& A) {
        // Get the place (position in the ascending order) of each number.
        vector<int> sorted_A(A), places(A.size());
        sort(sorted_A.begin(), sorted_A.end());
        for (int i = 0; i < A.size(); ++i) {
            places[i] = 
                lower_bound(sorted_A.begin(), sorted_A.end(), A[i]) -
                sorted_A.begin();
        }
        // Count the smaller elements after the number.
        long long count = 0;
        vector<int> bit(A.size() + 1);
        for (int i = A.size() - 1; i >= 0; --i) {
            count += query(bit, places[i]);
            add(bit, places[i] + 1, 1);
        }
        return count;
    }

private:
    void add(vector<int>& bit, int i, int val) {
        for (; i < bit.size(); i += lower_bit(i)) {
            bit[i] += val;
        }
    }

    int query(const vector<int>& bit, int i) {
        int sum = 0;
        for (; i > 0; i -= lower_bit(i)) {
            sum += bit[i];
        }
        return sum;
    }

    int lower_bit(int i) {
        return i & -i;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// Merge sort solution.
class Solution2 {
public:
    /**
     * @param A an array
     * @return total of reverse pairs
     */
    long long reversePairs(vector<int>& A) {
        long long count = 0;
        vector<pair<int, int>> num_idxs;
        for (int i = 0; i < A.size(); ++i) {
            num_idxs.emplace_back(A[i], i);
        }
        countAndMergeSort(&num_idxs, 0, num_idxs.size() - 1, &count);
        return count;
    }

private:
    void countAndMergeSort(vector<pair<int, int>> *num_idxs, int start, int end, long long *count) {
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
