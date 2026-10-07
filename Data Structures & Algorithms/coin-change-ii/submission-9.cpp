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
        if (amount < 0 || index >= coins.size()) {
            return 0;
        } else if (amount == 0) {
            return 1;
        }

        if (dp[amount][index] != -1) {
            return dp[amount][index];
        }

        // Choice 1: Use the current coin (stay on same index)
        int take = recurse(amount - coins[index], coins, dp, index);

        // Choice 2: Skip the current coin (move to next index)
        int skip = recurse(amount, coins, dp, index + 1);

        dp[amount][index] = take + skip;
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
