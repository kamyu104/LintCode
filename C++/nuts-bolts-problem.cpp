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
            // Random chossing a bolt as a pivot for nuts partition.
            default_random_engine gen((random_device())());
            uniform_int_distribution<int> dis(left, right);
            int pivot = dis(gen);
            
            // Use the pivot bolt to make a partition of nuts. 
            // The we could know the index where the pivot (bolt, nut) pair should be in sorted order.
            pivot = partition(nuts, left, right, bolts[pivot]);
 
            // Using the nut in the pivot bolt to make a partition of bolts.
            partition(bolts, left, right, nuts[pivot]);
 
            // Now, both nuts and bolts are partitioned by the pivot nut-bolt pair.
            // The pivot nut-bolt pair is also in the correct index of the sorted order.
            // Recursively do the same thing in the left and right side of the pivot.
            quickSort(nuts, bolts, left, pivot - 1);
            quickSort(nuts, bolts, pivot + 1, right);
        }
    }
 
    // All the smaller elements should be in the left side of the pivot,
    // and all the bigger elements should in the right side of the pivot.
    int partition(vector<int>& arr, int left, int right, int pivot) {
        for (int i = left; i < right; ) {
            if (Compare::cmp(arr[i], pivot) == SMALLER ||  // Smaller.
                (Compare::cmp(arr[i], pivot) == REVERSE &&
                 Compare::cmp(pivot, arr[i]) == BIGGER)) {
                swap(arr[left++], arr[i++]);
            } else if (Compare::cmp(arr[i], pivot) == BIGGER ||  // Bigger.
                      (Compare::cmp(arr[i], pivot) == REVERSE &&
                       Compare::cmp(pivot, arr[i]) == SMALLER)) {
                ++i;
            } else { // Equal.
                swap(arr[i], arr[right]);
            }
        }
        // Put the pivot to the partition index.
        swap(arr[left], arr[right]);
        
        // Return the partition index of an array.
        return left;
    }
};
