class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        //用动态规划，开动规数组dp[i][j]表示以位置（i,j）为正方形的右下顶点时所构成的最大边长
        //有状态转移方程dp[i][j] = min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        int res = 0;
        vector<vector<int> > dp(m, vector<int>(n));
        if (matrix[0][0] == '0') dp[0][0] = 0;
        else dp[0][0] = 1;
        res = dp[0][0] * dp[0][0];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0) continue;
                else if (i == 0 || j ==0) dp[i][j] = matrix[i][j] == '1' ? 1 : 0;
                else dp[i][j] = matrix[i][j] == '1' ? min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1 : 0;
                res = max(res, dp[i][j] * dp[i][j]);
            }
        }
        return res;
    }
};
