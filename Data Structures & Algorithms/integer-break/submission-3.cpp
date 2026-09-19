class Solution {
public:
    int integerBreak(int n) {
        auto dp = vector<int>(n + 1, 1);
        if (n == 2) {
            return 1;
        }
        for (int i = 2; i < n; ++i) {
            dp[i] = i;
            for (int j = 1; j <= i / 2; ++j) {
                dp[i] = max(dp[i], dp[j] * dp[i - j]);
            }
            // cout << i << " " << dp[i] << '\n';
        }

        dp[n] = n - 1;
        for (int j = 1; j <= n / 2; ++j) {
            dp[n] = max(dp[n], dp[j] * dp[n - j]);
        }

        return dp[n];
    }
};