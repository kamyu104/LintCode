// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        for (int i = 0; i < A.size(); i++) {
            minHeapify(A, i);
        }
    }
    
    void minHeapify(vector<int>& A, int index) {
        while ((index - 1) / 2 >= 0) {
            int parent = (index - 1) / 2;
            if (A[index] < A[parent]) {
                swap(A[parent], A[index]);
                index = parent;
            }
            else {
                break;
            }
        }
    }
};
