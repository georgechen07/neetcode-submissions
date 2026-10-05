class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        auto res = 0;
        int total_sum = std::accumulate(nums.begin(), nums.end(), 0);
    
        if (std::abs(target) > total_sum) {
            return 0;
        }

        auto dp = vector<vector<int>>(nums.size(), vector<int>(4001, -1));
        res += recurse(nums, target, 0, dp);

        return res;
    }

    int recurse(vector<int>& nums, int target, int index, vector<vector<int>>& dp) {
        if (index == nums.size()) {
            return target == 0 ? 1 : 0; 
        } 
        
        int offset_target = target + 2000;
        
        if (dp[index][offset_target] != -1) {
            return dp[index][offset_target];
        }
        
        int ways = recurse(nums, target + nums[index], index + 1, dp) + 
                recurse(nums, target - nums[index], index + 1, dp);
                
        return dp[index][offset_target] = ways;
    }
    // dp[3][2] = 1
    // 
};
