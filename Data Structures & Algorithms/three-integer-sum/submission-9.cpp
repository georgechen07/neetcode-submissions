class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        // 3, -2, 1, 0
        // -2, 0, 1, 3

        for (int i = 0; i < nums.size(); i++) {
            if (i >= 1 && nums[i] == nums[i - 1]) {
                continue;
            }
            int l = i + 1;
            int r = nums.size() - 1;
            int target = -nums[i];
            bool pushed = false;

            while (l < r) {
                if (pushed) {
                    l++;
                    r--;
                    if (nums[l] != nums[l - 1]) {
                        pushed = false;
                    }
                }
                while (l < r && nums[l] + nums[r] < target) {
                    l++;
                    pushed = false;
                }
                while (l < r && nums[l] + nums[r] > target) {
                    r--;
                    pushed = false;
                }
                if (r <= l || pushed || nums[l] + nums[r] != target) {
                    continue;
                }
                cout << "i = " << i << " l = " << l << " r = " << r << '\n';
                res.push_back({nums[i], nums[l], nums[r]});
                pushed = true;
            }
        }

        return res;
    }
};
