class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //用dp[i][j]表示text1以text1[i-1]结尾，text2以text2[j-1]结尾时两者的最长公共子序列的长度
        //此时对dp[i][j]来说，有可能只有text1[i-1]在最长公共子序列中，或者只有text2[j-1]在最长公共子序列中，或者两者都在最长公共子序列中，或者两者都不在最长公共子序列中
        //分四种情况讨论：
        //当text1[i-1] == text2[j-1]时，该相等值一定在最长公共子序列里，此时dp[i][j] = dp[i-1][j-1] + 1
        //当text1[i-1] != text2[j-1]时，最长公共子序列不能+1， 此时dp[i][j] = max(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]),
        //分别对应只有text2[j-1]在最长公共子序列中，只有text1[i-1]在最长公共子序列中，两者都不在最长公共子序列中的情况
        if (text1.empty() || text2.empty()) return 0;
        vector<vector<int> > dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = 1; i < dp.size(); i++)
        {
            for (int j = 1; j < dp[i].size(); j++)
            {
                if (text1[i-1] == text2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], max(dp[i][j-1], dp[i-1][j-1]));
            }
        }
        return dp.back().back();
    }
};
