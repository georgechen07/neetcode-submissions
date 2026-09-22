class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.contains(target - nums[i])) return vector<int>{m[target - nums[i]], i};
            m[nums[i]] = i;
        }
        return vector<int>{};
        // m[-1] = 0
        // m[-2] = 1
        // m[-3] = 2
        // m[-4] = 3
        // m[-5] = 4
    }
};
