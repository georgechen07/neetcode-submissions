class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int prev_end = intervals[0][0];
        int res = 0;
        for (auto const& interval : intervals) {
            if (interval[0] < prev_end) {
                res++;
                prev_end = min(prev_end, interval[1]);
            } else {
                prev_end = interval[1];
            }
        }

        return res;
    }
};
