/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return true;
        }
        
        sort(intervals.begin(), intervals.end(), [](auto const& lhs, auto const& rhs) {
            return lhs.start < rhs.start;
        });

        int prev_start = 1000000;
        int prev_end = 0;
        for (auto const& interval : intervals) {
            if (interval.start < prev_end) {
                return false;
            }
            prev_start = interval.start;
            prev_end = interval.end;
        }

        return true;
    }
};
