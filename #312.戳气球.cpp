class Solution {
public:
    int maxCoins(vector<int>& nums) {
        //用动态规划，用状态dp[i][j]表示在区间i~j间戳气球时得到的最大值
        //可以看到每次戳都有三个数字参与相乘，可以用一个游标k表示最后一个戳破的气球，k在i~j之间游走，不断更新dp[i][j]为较大值
        //这样的游标我们见过很多次，如果总结可以发现他们都是用来更新动规数组为区间内的最值，k应该具有唯一性，比如最后一个子数组的左边界（#410）最后一个戳破的气球（#312）
        //k将i~j划分为三个部分，i~k-1, k, k+1~j 
        //每个k都应该有dp[i][j] = max(dp[i][j], dp[i][k - 1] + nums[i - 1]*nums[k]*nums[j + 1] + dp[k + 1][j]) (i <= k <= j)
        //注意这里i是可以大于j的，不过这样的动规元素应该被置为0
        //区间长度应该是从小到大的，因为大区间要用到小区间的动规值
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int> > dp(n + 2, vector<int>(n + 2, 0));//求最大值初始置为0，求最小值初始置为INT_MAX
        for (int len = 0; len <= n - 1; len++) //最终返回的应该是dp[1][n],所以len最大应该为n-1
        {
            for (int i = 1; i + len <= n; i++)//第一个 最后一个气球不能戳
            {
                int j = i + len;
                for (int k = i; k <= j; k++)
                {
                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + nums[i - 1]*nums[k]*nums[j + 1] + dp[k + 1][j]);
                }
            }
        }
        return dp[1][n];
    }
};
