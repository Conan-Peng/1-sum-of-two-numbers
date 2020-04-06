class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.empty()) return 0;
        vector<vector<int> > dp(prices.size(), vector<int>(2, INT_MIN));
        for (int i = 0; i < prices.size(); i++)
        {
            if (i == 0) 
            {
                dp[i][0] = 0;
                dp[i][1] = -prices[i] - fee;
                continue;
            }
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i] - fee);
        }
        return dp[prices.size() - 1][0];
    }
};
