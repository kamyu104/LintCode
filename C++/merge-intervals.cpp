// Time:  O(nlogn)
// Space: O(1)

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
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.empty()) {
            return intervals;
        }

        sort(intervals.begin(), intervals.end(),
        [](const Interval& a, const Interval& b) {
             return a.start < b.start;               
        });

        vector<Interval> result = {intervals[0]};
        for (int i = 1; i < intervals.size(); ++i) {
            Interval& prev = result.back();
            if (intervals[i].start <= prev.end) { 
                prev.end = max(prev.end, intervals[i].end);
            } else {
                result.emplace_back(intervals[i]);
            }
        }

        return result;
    }
};
