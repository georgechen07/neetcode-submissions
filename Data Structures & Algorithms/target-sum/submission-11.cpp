class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        auto res = 0;
        auto dp = vector<unordered_map<int, int>>(nums.size());
        res += recurse(nums, target, 0, dp);

        return res;
    }

    int recurse(vector<int>& nums, int target, int index, vector<unordered_map<int, int>>& dp) {
        // cout << index << ' ' << target << '\n';
        auto res = 0;
        if (index == nums.size() && target != 0) {
            return 0;
        } else if ((index == nums.size() && target == 0)) {
            return 1;
        } else if (dp[index].contains(target)) {
            return dp[index][target];
        }
        auto rec_res1 = recurse(nums, target + nums[index], index + 1, dp);
        if (rec_res1) {
            dp[index][target] += rec_res1;
            res += rec_res1;
        }
        auto rec_res2 = recurse(nums, target - nums[index], index + 1, dp);
        if (rec_res2) {
            dp[index][target] += rec_res2;
            res += rec_res2;
        }

        if (rec_res1 == 0 && rec_res2 == 0) {
            dp[index][target] = 0;
        }
        // cout << res << '\n';
        return res;
    }
    // dp[3][2] = 1
    // 
};
