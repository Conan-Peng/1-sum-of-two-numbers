class Solution {
public:
    int minDistance(string word1, string word2) {
        //笔试的时候注意一些暴力求解的方法，注意一些边界条件的列出，注意算法轮子的积累（常用求解方法模板，如二分查找，回溯，动规，快排，STL中的hashmap和treemap的使用等）
        //能得一分是一分
        if (word1.empty() && word2.empty()) return 0;
        int m = word1.size(), n = word2.size();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, INT_MAX));
        for (int i = 0; i < m + 1; i++)
        {
            dp[i][0] = i;
        }
        for (int i = 0; i < n + 1; i++)
        {
            dp[0][i] = i;
        }
        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(dp[i][j-1], min(dp[i-1][j-1], dp[i-1][j])) + 1; //判断左，左上，上，分别代表着增加，修改，删除待编辑数组的（i-1,j-1)位置的元素，典型的具有重复子问题的特征
            }
        }
        return dp[m][n];        
    }
};
