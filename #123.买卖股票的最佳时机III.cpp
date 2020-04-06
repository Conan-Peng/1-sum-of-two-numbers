class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //用三维数组dp[i][j][k]表示第i天，已经进行了j笔交易，持有（k=1)或不持有（k=0)股票所能获得的最大利润
        //dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i])
        //dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i])
        if (prices.empty()) return 0;
        vector<vector<vector<int> > > dp(prices.size(), vector<vector<int> >(3, vector<int>(2, INT_MIN)));
        for (int i = 0; i < prices.size(); i++)
        {
            for (int j = 0; j <= 2; j++)
            {
                if (i == 0) 
                {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = -prices[i];
                    continue;
                }
                if (j == 0)
                {
                    dp[i][j][0] = 0;
                    continue;
                }
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i]);
            }
        }
        return dp[prices.size()-1][2][0];
    }
};
