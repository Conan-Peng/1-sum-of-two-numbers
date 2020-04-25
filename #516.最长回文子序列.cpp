class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.empty()) return 0;
        vector<vector<int> > dp(s.size(), vector<int>(s.size(), 0));//dp[i][j]表示区间i~j内的最长回文子序列的长度
        for (int i = 0; i < s.size(); i++)
        {
            dp[i][i] = 1;
        }
        for (int len = 1; len < s.size(); len++) //这种斜着遍历的方式多次遇到，因为dp[i][j]用到了左，下，左下的三个已知值dp[i][j-1],dp[i+1][j],dp[i+1][j-1]，所以我们通常会先给定斜着的对角线的值dp[i][j](i == j), 然后依次斜着遍历，这种方法适用于dp[i][j]中的i,j分别是区间的两端点，类似的我们处理过877石子游戏，312戳气球
        {
            for (int i = 0; i + len < s.size(); i++)
            {
                int j = i + len;
                if (s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2;
                else dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
        }
        return dp[0][s.size()-1];
    }
};
