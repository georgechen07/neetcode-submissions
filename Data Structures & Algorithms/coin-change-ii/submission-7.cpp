class Solution {
public:
    int change(int amount, vector<int>& coins) {
        auto dp = vector<vector<int>>(amount + 1, vector<int>(coins.size(), -1));
        auto res = recurse(amount, coins, dp, 0);

        // for (auto const& val : dp) {
        //     for (auto const& num : val) {
        //         cout << num << ' ';
        //     }
        //     cout << '\n';
        // }

        return res;
    }

    int recurse(int amount, vector<int>& coins, vector<vector<int>>& dp, int index) {
        if (amount < 0) {
            return 0;
        } else if (amount == 0) {
            return 1;
        }

        if (dp[amount][index] != -1) {
            return dp[amount][index];
        }

        int total_ways = 0;
        for (int i = index; i < coins.size(); ++i) {
            auto coin = coins[i];
            if (coin <= amount) {
                // cout << amount << " < " << dp[amount] << ", ";
                total_ways += recurse(amount - coin, coins, dp, i);
                // cout << amount << " > " << dp[amount] << '\n';
            }
        }

        dp[amount][index] = total_ways;
        // 1 2 3
        // 6
        // 1 1 1 1 1 1
        // (1 1 1 1) + 2
        // dp[2][0] += 1
        // (2 2) + 2
        // 

        return dp[amount][index];
        // return 1;
        // dp[1] += 1;
        // dp[1] += 0;
        // dp[1] += 0;
        // return dp[1];
        // dp[2] += 1;
        // return 1;
        // dp[2] += 1;
        // dp[2] += 0;
        // return dp[2];
        // dp[3] += 2;
        // return 1
        // dp[3] += 1;
        // return dp[3];
        // dp[4] += 1;

    }
};
