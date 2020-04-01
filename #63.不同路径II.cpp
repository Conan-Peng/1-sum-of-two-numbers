class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //用动态规划，每个位置只能由其上方或者左方不为1的位置进入
        //用动规数组dp[i][j]表示到达位置（i,j)的所有不同路径的数目，有dp[i][j] = (1 - obstacleGrid[i - 1][j]) * dp[i - 1][j] + (1 - obstacleGrid[i][j - 1]) * dp[i][j - 1]
        vector<vector<long> > dp(obstacleGrid.size(), vector<long>(obstacleGrid[obstacleGrid.size() - 1].size()));
        if (obstacleGrid[0][0] == 1 || obstacleGrid[obstacleGrid.size() - 1].back() == 1) return 0;
        dp[0][0] = 1;
        for (int i = 0; i < obstacleGrid.size(); i++)
        {
            for (int j = 0; j < obstacleGrid[i].size(); j++)
            {
                if (i == 0 && j == 0) continue;
                else if (i == 0) dp[i][j] = (1 - obstacleGrid[i][j - 1]) * dp[i][j - 1];
                else if (j == 0) dp[i][j] = (1 - obstacleGrid[i - 1][j]) * dp[i - 1][j];
                else dp[i][j] = (1 - obstacleGrid[i - 1][j]) * dp[i - 1][j] + (1 - obstacleGrid[i][j - 1]) * dp[i][j - 1];
            }
        }
        return (int)dp[obstacleGrid.size() - 1].back();
    }
};
