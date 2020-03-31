class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        //用动态规划来做，给定二维动规数组dp[i][j],表示亚在区间i~j内操作时，亚比李多拿的石子数，
        //如果亚从左侧拿，那么下一步李就会从i-1~j中拿最佳选择，由于李和亚都是最优选择，那么李比亚多拿的石子数也是dp[i - 1][j],
        //此时有递推式dp[i][j] = piles[i] - dp[i + 1][j]
        //另一种可能是亚从右侧拿，同理有dp[i][j] = piles[j] - dp[i][j - 1]
        //因此有状态转移方程：dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1])
        //base case为dp[i][i] = piles[i];
        int n = piles.size();
        vector<vector<int> > dp(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = piles[i];
        }
        for (int len = 1; len <= n - 1; len++)//i和j之间的距离
        {
            for (int i = 0; i + len < n; i++)
            {
                int j = i + len;
                dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] > 0 ? true : false;
    }
};
