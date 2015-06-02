// Time:  O(nlogn)
// Space: O(1)

/**
 * class Compare {
 *     public:
 *     static int cmp(int a, int b);
 * };
 * You can use Compare::cmp(a, b) to compare nuts "a" and bolts "b",
 * if "a" is bigger than "b", it will return 1, else if they are equal,
 * it will return 0, else if "a" is smaller than "b", it will return -1.
 * When "a" is not a nut or "b" is not a bolt, it will return 2, which is not valid.
*/
class Solution {
public:
    typedef enum { SMALLER = -1, EQUAL = 0, BIGGER = 1, REVERSE = 2 } CompareResult;
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @return: nothing
     */
    void sortNutsAndBolts(vector<int> &nuts, vector<int> &bolts) {
        quickSort(nuts, bolts, 0, nuts.size() - 1);
    }
 
private:
    // Method which works just like quick sort
    void quickSort(vector<int>& nuts, vector<int>& bolts, int left, int right) {
        if (left < right) {
            // Random choice of bolts array as pivot for nuts partition.
            default_random_engine gen((random_device())());
            uniform_int_distribution<int> dis(left, right);
            int pivot = dis(gen);
            
            // Find the place where the pivot will be, let it be k_th_element.
            pivot = partition(nuts, left, right, bolts[pivot]);
 
            // Using the index of nuts k_th_element as a pivot for bolts partition.
            partition(bolts, left, right, nuts[pivot]);
 
            // Now, both nuts and bolts are partitioned by k_th_element.
            quickSort(nuts, bolts, left, pivot - 1);
            quickSort(nuts, bolts, pivot + 1, right);
        }
    }
 
    int partition(vector<int>& arr, int left, int right, int pivot) {
        int i = left;
        for (int j = left; j < right; ++j) {
            if (Compare::cmp(arr[j], pivot) == CompareResult::SMALLER ||
                (Compare::cmp(arr[j], pivot) == CompareResult::REVERSE &&
                 Compare::cmp(pivot, arr[j]) == CompareResult::BIGGER)){
                swap(arr[i], arr[j]);
                ++i;
            } else if (Compare::cmp(arr[j], pivot) == CompareResult::EQUAL ||
                      (Compare::cmp(arr[j], pivot) == CompareResult::REVERSE &&
                       Compare::cmp(pivot, arr[j]) == CompareResult::EQUAL)){
                swap(arr[j], arr[right]);
                --j;
            }
        }
        swap(arr[i], arr[right]);
 
        // Return the partition index of an array.
        return i;
    }
};
