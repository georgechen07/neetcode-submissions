class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        while (i < intervals.size() && intervals[i][0] < newInterval[0] && intervals[i][1] < newInterval[0]) {
            ++i;
        }
        if (i == intervals.size()) {
            intervals.push_back(newInterval);
            return intervals;
        }

        if (newInterval[1] < intervals[i][0]) {
            intervals.insert(intervals.begin() + i, newInterval);
            return intervals;
        } else {
            intervals[i][0] = min(newInterval[0], intervals[i][0]);
            intervals[i][1] = max(newInterval[1], intervals[i][1]);
        } 

        int j = intervals.size() - 1;
        while (j > i) {
            if (intervals[j][0] <= intervals[i][1]) {
                intervals[i][1] = max(intervals[i][1], intervals[j][1]);
                intervals.erase(intervals.begin() + i + 1, intervals.begin() + j + 1);
                break;
            }
            --j;
        }

        return intervals;
    }
};
