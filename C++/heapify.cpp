// Time:  O(n)
// Space: O(1)

// Bottom-Up.
class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        for (int i = A.size() / 2; i >= 0; --i) {
            sift_down(A, i);
        }
    }

    void sift_down(vector<int>& A, int index) {
        while (index < A.size()) {
            int smallest = index;
            if (index * 2 + 1 < A.size() && A[index * 2 + 1] < A[smallest]) {
                smallest = index * 2 + 1;
            }
            if (index * 2 + 2 < A.size() && A[index * 2 + 2] < A[smallest]) {
                smallest = index * 2 + 2;
            }
            if (smallest == index) {
                break;
            }
            swap(A[smallest], A[index]);
            index = smallest;
        }
    }
};


// Time:  O(nlogn)
// Space: O(1)
// Top-Down.
class Solution2 {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        for (int i = 0; i < A.size(); ++i) {
            sift_up(A, i);
        }
    }

    void sift_up(vector<int>& A, int index) {
        while ((index - 1) / 2 >= 0) {
            int parent = (index - 1) / 2;
            if (A[index] < A[parent]) {
                swap(A[parent], A[index]);
                index = parent;
            } else {
                break;
            }
        }
    }
};

