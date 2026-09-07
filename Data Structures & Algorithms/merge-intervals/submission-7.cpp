class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        res.reserve(intervals.size());
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].front() <= res.back().back()) {
                res.back().back() = max(intervals[i].back(), res.back().back());
            } else {
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};
