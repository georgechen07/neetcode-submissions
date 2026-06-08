class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int res[10000] = {0};

        if (amount == 0) {
            return 0;
        }

        for (int i = 0; i <= amount; i++) {
            for (const int& val : coins) {
                if (i == val) {
                    res[i] = 1;
                    break;
                } else if (i - val > 0 && res[i - val] != -1) {
                    if (res[i] <= 0 || res[i - val] + 1 < res[i]) {
                        res[i] = res[i - val] + 1;
                    }
                } else if (res[i] == 0) {
                    res[i] = -1;
                }
            }
        }

        for (int k = 9000; k <= amount; k++) {
            // if (res[k] != -1) {
                cout << k << " " << res[k] << '\n';
            // }
        }

        return res[amount];
    }
};
