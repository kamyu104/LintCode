// Time:  O(nlogn)
// Space: O(n)

// BST solution.
/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    struct Compare {
        bool operator() (const Interval&a, const Interval&b) {
            return a.start != b.start ? a.start < b.start : a.end < b.end;
        }
    };
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        int max_planes = 0;
        multiset<int> bst;
        sort(airplanes.begin(), airplanes.end(), Compare());
        
        for (const auto& i : airplanes) {
            bst.insert(i.end);
            while (*bst.begin() <= i.start) {
                bst.erase((bst.begin()));
            }
            if (bst.size() > max_planes) {
                max_planes = bst.size();
            }
        }
        return max_planes;
    }
};

// Heap solution.
class Solution2 {
public:
    struct Compare {
        bool operator() (const Interval&a, const Interval&b) {
            return a.start != b.start ? a.start < b.start : a.end < b.end;
        }
    };
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        int max_planes = 0;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        sort(airplanes.begin(), airplanes.end(), Compare());
        
        for (const auto& i : airplanes) {
            min_heap.emplace(i.end);
            while (min_heap.top() <= i.start) {
                min_heap.pop();
            }
            if (min_heap.size() > max_planes) {
                max_planes = min_heap.size();
            }
        }
        return max_planes;
    }
};