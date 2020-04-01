class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //用动规的方法，动规数组dp[i][j]表示到（i,j)位置上的最短路径
        //有状态转移方程dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j], base case为dp[0][0] = grid[0][0]
        vector<vector<int> > dp(grid);
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (i == 0 && j == 0) continue;
                else if (i == 0) dp[i][j] += dp[i][j - 1];
                else if (j == 0) dp[i][j] += dp[i - 1][j];
                else dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[dp.size() - 1].back();
    }
};
