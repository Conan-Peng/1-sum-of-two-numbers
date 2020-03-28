class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //动态规划，开一个数组dp[i][j]表示最后一行元素到第i行j列元素的最短路径和,从下向上查找计算出dp[0][0]即可得到结果。
        //本题如果从上到下查找最后的结果需要判断最后一行的所有元素，不如从下到上方便,而且从下到上每个元素都能找到左右两个路径不用判断指针是否不合法
        //递推式为dp[i][j] = min(dp[i + 1][j + 1], dp[i + 1][j]) + triangle[i][j]
        if (triangle.empty()) return 0;
        vector<vector<int> > dp(triangle);
        for (int i = triangle.size() - 2; i >= 0; i--)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                dp[i][j] += min(dp[i + 1][j + 1], dp[i + 1][j]);
            }
        }
        return dp[0][0];


    }
};
