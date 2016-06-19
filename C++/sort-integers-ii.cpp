// Time:  O(nlogn)
// Space: O(n)

// Merge sort. (stable)
class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers2(vector<int>& A) {
        mergeSort(&A, 0, A.size() - 1);
    }

private:
    void mergeSort(vector<int> *A, int start, int end) {
        if (end - start <= 0) {
            return;
        }
        int mid = start + (end - start) / 2;
        mergeSort(A, start, mid);
        mergeSort(A, mid + 1, end);

        int l = start;
        vector<int> tmp;
        for (int i = mid + 1; i <= end; ++i) {
            // Merge the two sorted arrays into tmp.
            while (l <= mid && (*A)[l] <= (*A)[i]) {
                tmp.emplace_back((*A)[l++]);
            }
            tmp.emplace_back((*A)[i]);
        }
        while (l <= mid) {
            tmp.emplace_back((*A)[l++]);
        }
        // Copy tmp back to A.
        copy(tmp.begin(), tmp.end(), A->begin() + start);
    }
};

// Time:  O(nlogn)
// Space: O(1)
// Heap sort. (unstable)
class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers2(vector<int>& A) {
        heapify(&A);
        for (int i = static_cast<int>(A.size()) - 1; i >= 0; --i) {
            swap(A[0], A[i]);
            sift_down(&A, 0, i);
        }
    }

private:
    void heapify(vector<int> *A) {
        for (int i = A->size() / 2; i >= 0; --i) {
            sift_down(A, i, A->size());
        }
    }

    void sift_down(vector<int> *A, int index, int size) {
        while (index < size) {
            int largest = index;
            if (index * 2 + 1 < size && (*A)[index * 2 + 1] > (*A)[largest]) {
                largest = index * 2 + 1;
            }
            if (index * 2 + 2 < size && (*A)[index * 2 + 2] > (*A)[largest]) {
                largest = index * 2 + 2;
            }
            if (largest == index) {
                break;
            }
            swap((*A)[largest], (*A)[index]);
            index = largest;
        }
    }
};

// Time:  O(nlogn) ~ O(n^2)
// Space: O(logn) ~ O(n)
// Quick sort. (unstable)
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
