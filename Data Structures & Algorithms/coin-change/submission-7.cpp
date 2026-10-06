class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp;
        dp.push_back(0);
        for (int i = 1; i <= amount; ++i) {
            dp.push_back(-1);
            for (auto const& coin : coins) {
                if (i == coin) {
                    dp[i] = 1;
                    break;
                } else if (dp.size() > i - coin) {
                    if (dp[i] == -1 && dp[i - coin] != -1) {
                        dp[i] = dp[i - coin] + 1;
                    } else if (dp[i - coin] != -1) {
                        dp[i] = min(dp[i - coin] + 1, dp[i]);
                    }
                }
            }
        }

        // for (auto const& c : dp) {
        //     cout << c << '\n';
        // }
        return dp[amount];
    }
};
