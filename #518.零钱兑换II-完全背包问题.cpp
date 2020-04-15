class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //完全背包问题，每个物品的数量是无限的，此时在状态转移方程上有细微差别
        //dp[i][j]表示前i个硬币凑出来金额为j的组合数，dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]],注意这里最后一项是dp[i]而不是dp[i-1]，这是因为硬币数是无限的
        if (coins.empty() && !amount) return 1;
        vector<vector<int> > dp(coins.size() + 1, vector<int>(amount + 1, 0));
        for (int i = 1; i < dp.size(); i++)
        {
            for (int j = 0; j < dp[i].size(); j++)
            {
                if (j == 0)
                {
                    dp[i][j] = 1;
                    continue;
                }
                if (j - coins[i-1] < 0) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
            }
        }
        return dp[coins.size()][amount];
    }
};
