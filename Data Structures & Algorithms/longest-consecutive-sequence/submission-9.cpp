class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        auto m = unordered_map<int, int>();
        int res = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (m.contains(nums[i] - 1)) {
                m[nums[i]] = m[nums[i] - 1] + 1;
            } else {
                m[nums[i]] = 1;
            }
            update(m, nums[i], res);
        }

        for (auto const& member : m) {
            cout << member.first << " " << member.second << '\n';
        }
        return res;
    }

    void update(unordered_map<int, int>& m, int key, int& res) {
        res = max(res, m[key]);
        if (m.contains(key + 1) && m[key] + 1 > m[key + 1]) {
            m[key + 1] = m[key] + 1;
            update(m, key + 1, res);
        }
    }
};
