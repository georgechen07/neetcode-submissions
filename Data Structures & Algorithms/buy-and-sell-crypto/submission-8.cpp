class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best_profit = 0;
        int min_buy = prices[0];

        for (auto const& price : prices) {
            best_profit = max(best_profit, price - min_buy);
            min_buy = min(min_buy, price);
        }

        return best_profit;
    }
};
