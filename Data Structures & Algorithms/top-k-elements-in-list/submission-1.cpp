class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        auto count = unordered_map<int, int>();
        auto buckets = vector<vector<int>>(nums.size());

        for (auto const& num : nums) {
            ++count[num];
        }

        for (auto const& [number, freq] : count) {
            buckets[freq - 1].push_back(number);
        }

        auto res = vector<int>();
        int i = buckets.size() - 1;
        while (res.size() < k) {
            while (buckets[i].empty()) {
                --i;
            }
            for (auto const& number : buckets[i]) {
                res.push_back(number);
            }
            --i;
        }

        return res;
    }
};
