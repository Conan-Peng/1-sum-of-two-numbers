class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //使用动态规划，dp[i][j]表示使用前i个硬币凑出金额j所需要的最少的硬币个数
        //dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]] + 1)
        vector<vector<int> > dp(coins.size() + 1, vector<int>(amount + 1, INT_MAX));
        for (int i = 0; i < coins.size() + 1; i++)
        {
            for (int j = 0; j < amount + 1; j++)
            {
                if (j == 0)
                {
                    dp[i][j] = 0;
                    continue;
                }
                if (i == 0)
                {
                    dp[i][j] = -1;
                    continue;
                }
                //看所有可能的情况
                if (j - coins[i-1] < 0) dp[i][j] = dp[i-1][j];
                else if (dp[i-1][j] == -1 && dp[i][j-coins[i-1]] != -1) dp[i][j] = dp[i][j-coins[i-1]] + 1;
                else if (dp[i-1][j] != -1 && dp[i][j-coins[i-1]] == -1) dp[i][j] = dp[i-1][j];
                else if (dp[i-1][j] == -1 && dp[i][j-coins[i-1]] == -1) dp[i][j] = -1;
                else dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]] + 1);
            }
        }
        return dp[coins.size()][amount];
    }
};
