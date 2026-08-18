class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        auto l = nums.begin();
        auto r = nums.begin();

        priority_queue<pair<int, int>> pq;
        vector<int> res;
        while (r - l < k) {
            pq.push({*r, r - l});
            r++;
        }
        res.push_back(pq.top().first);
        
        while (r < nums.end()) {
            pq.push({*r, r - nums.begin()});
            ++l;
            while (pq.top().second < l - nums.begin()) {
                pq.pop();
            }
            res.push_back(pq.top().first);
            ++r;
        }

        return res;
    }
};
