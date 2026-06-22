class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] == 0) {
                dp[i] = -1;
            } else {
                for (int j = nums[i]; j > 0; j--) {
                    if (i + j >= nums.size()) {
                        continue;
                    }

                    if (dp[i] == 0) {
                        dp[i] = dp[i + j] + 1;
                    } else if (dp[i + j] >= 0 && dp[i + j] + 1 < dp[i]) {
                        dp[i] = dp[i + j] + 1;
                    }
                }
            }
        }

        for (int a = 0; a < dp.size(); a++) {
            cout << dp[a] << '\n';
        }

        return dp[0];
    }
};
