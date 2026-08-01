class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto const& num : nums) {
            if (pq.size() < k || num > pq.top()) {
                if (pq.size() == k) {
                    pq.pop();
                }
                pq.push(num);
            }
        }

        return pq.top();
    }
};
