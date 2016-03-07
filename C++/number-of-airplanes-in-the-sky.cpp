// Time:  O(nlogn)
// Space: O(n)

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
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        int max_planes = 0;
        int planes = 0;

        vector<int> starts, ends;
        for (const auto& i : airplanes) {
            starts.emplace_back(i.start);
            ends.emplace_back(i.end);
        }


        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int s = 0, e = 0;
        while (s < starts.size()) {
            if (starts[s] < ends[e]) {
                ++planes;
                max_planes = max(max_planes, planes);
                ++s;
            } else {
                --planes;
                ++e;
            }
        }

        return max_planes;
    }
};

class Solution2 {
public:
    using Endpoint = enum {START, END};

    struct Point {
        Endpoint type;
        int time;
    };

    struct Compare {
        bool operator() (const Point&a, const Point&b) {
            return a.time != b.time ? a.time < b.time : a.type > b.type;
        }
    };

    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        int max_planes = 0;
        int planes = 0;

        vector<Point> points;
        for (const auto& i : airplanes) {
            points.emplace_back(Point{START, i.start});
            points.emplace_back(Point{END, i.end});
        }
        sort(points.begin(), points.end(), Compare());

        for (const auto& i : points) {
            if (i.type == START) {
                ++planes;
                max_planes = max(max_planes, planes);
            } else {
                --planes;
            }
        }
        return max_planes;
    }
};

// BST solution.
class Solution3 {
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
            bst.emplace(i.end);
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
class Solution4 {
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
