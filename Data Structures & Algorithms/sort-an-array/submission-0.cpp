class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto const num : nums) {
            pq.push(num);
        }

        vector<int> res;
        res.reserve(nums.size());
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }
};