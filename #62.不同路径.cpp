class Solution {
public:
    int uniquePaths(int m, int n) {
        //用动态规划，每个位置只能由它的左侧或者上侧进入
        //用动规数组dp[i][j]表示到达位置(i,j)上总共有多少条不同的路径，i表示列，j表示行，则有状态转移方程dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        //base case为dp[0][0] = 1
        vector<vector<int> > dp(m, vector<int>(n));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0) continue;
               else if (i == 0) dp[i][j] = dp[i][j - 1];
               else if (j == 0) dp[i][j] = dp[i - 1][j];
               else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
