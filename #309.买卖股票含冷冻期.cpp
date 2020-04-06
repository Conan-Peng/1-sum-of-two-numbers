class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //二维数组dp[i][j]表示第i天持有(j=1)或不持有（j=0)股票时能获取的最大利润
        //dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
        //dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i]);
        if (prices.empty()) return 0;
        vector<vector<int> > dp(prices.size(), vector<int>(2, INT_MIN));
        for (int i = 0; i < prices.size(); i++)
        {
            if (i == 0)
            {
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
                continue;
            }
            if (i == 1)
            {
                dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
                dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
                continue;
            }
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i]);
        }
        return dp[prices.size()-1][0];
    }
};
