class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        //用动态规划，三维数组dp[i][j][l]表示第i天已完成j笔交易持有（l=1)或不持有(l=0)股票能获取的最大利润
        //dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i])
        //dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i])
        if (prices.empty()) return 0;
        int n = prices.size();
        if (k >= n/2) return helper(prices);//应对一个超时的测试用例，k大于n/2时直接以无限制交易来做
        int m = min(n/2, k);
        vector<vector<vector<int> > > dp(prices.size(), vector<vector<int> >(m+1, vector<int>(2, INT_MIN)));
        for (int i = 0; i < prices.size(); i++)
        {
            for (int j = 0; j < m+1; j++)
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
        return dp[prices.size()-1][m][0];
    }
    int helper(vector<int>& prices) {
        vector<vector<int> > dp(prices.size(), vector<int>(2, INT_MIN));
        for (int i = 0; i < prices.size(); i++)
        {
            //base case
            if (i == 0)
            {
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
                continue;
            }
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }
        return dp[prices.size()-1][0];
    }
};
