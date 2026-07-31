class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return sqrt((a[1]) * a[1] + (a[0]) * a[0]) > sqrt((b[1]) * b[1] + (b[0]) * b[0]);
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

        for (auto const& point : points) {
            pq.push(point);
        }

        vector<vector<int>> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }

};
