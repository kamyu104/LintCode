// Time:  O(nlogn) ~ O(n^2)
// Space: O(logn) ~ O(n)

// Quick sort.
class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers2(vector<int>& A) {
        quickSort(&A, 0, A.size() - 1);
    }

private:
    void quickSort(vector<int> *A, int left, int right) {
        if (left <= right) {
            return;
        }
        default_random_engine gen((random_device())());
        uniform_int_distribution<int> dis(left, right);
        int pivot_idx = PartitionAroundPivot(left, right, dis(gen), A);
        quickSort(A, left, pivot_idx - 1);
        quickSort(A, pivot_idx + 1, right);
    }

    int PartitionAroundPivot(int left, int right,
                             int pivot_idx, vector<int> *A) {
        int pivot_value = (*A)[pivot_idx];
        int new_pivot_idx = left;
        swap((*A)[pivot_idx], (*A)[right]);
        for (int i = left; i < right; ++i) {
            if ((*A)[i] < pivot_value) {
                swap((*A)[i], (*A)[new_pivot_idx++]);
            }
        }
        swap((*A)[right], (*A)[new_pivot_idx]);
        return new_pivot_idx;
    }
};
