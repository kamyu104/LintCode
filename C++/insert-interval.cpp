// Time:  O(n)
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
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        size_t i = 0;
        vector<Interval> result;
        // Insert intervals appeared before newInterval.
        while (i < intervals.size() && newInterval.start > intervals[i].end) {
            result.emplace_back(intervals[i++]);
        }

        // Merge intervals that overlap with newInterval.
        while (i < intervals.size() && newInterval.end >= intervals[i].start) {
            newInterval = {min(newInterval.start, intervals[i].start),
                max(newInterval.end, intervals[i].end)};
            ++i;
        }
        result.emplace_back(newInterval);

        // Insert intervals appearing after newInterval.
        result.insert(result.end(), intervals.cbegin() + i, intervals.cend());
        return result;
    }
};
