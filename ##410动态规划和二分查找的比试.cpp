class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        //动规数组一般最后都能直接返回最终结果
        //动规记忆的一般是前一步的值而不是操作
        //什么叫做最优子结构，就是说如果子结构能达到最优，那么当前结构就能达到最优。
        

        //1.本问题的暴力穷举可以为从后往前看，以每个位置为最后一个子序列的左边界，将前面所有元素划分为m-1个子序列，
        //2.前m-1个子序列需要是最优子结构，一直往前找到第m-1个元素，寻找所有位置中的最小值
        //3.而将前面所有元素划分为m-1个最优子序列又可以分解为在当前元素往前一位开始往前，继续1

        //每个位置再往前作为第一位开始往前遍历，将前面所有元素划分为m-2个子序列，寻找其中的最小值
        //因此我们假设动规数组为dp[i][j],表示前j个元素划分为i个子序列，其中的最小值
        
        //有递推式：dp[i][j] <- min(dp[i][j], max(dp[i - 1][k], sums[j] - sums[k])|k belongs to i-1~j-1),其中sums[j]表示前j个元素的和
        //base case为dp[0][0] = 0
        int n = nums.size();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, INT_MAX));//初始化多一行一列是为了存储前0个划分0个数组的情况，初始化INT_MAX是因为原题求最小值，便于更新
        //求前j个元素的和
        vector<long> sums(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        dp[0][0] = 0;
        for (int j = 1; j <=n; j++)//用前j个就全用前j个的思维方式，只需要在初始值时考虑数组不越界即可
        {
            for (int i = 1; i <= m; i++)
            {
                for (int k = i - 1; k < j; k++)//用k扫一遍是因为j就是前j个，它不能变，但是k可以表示最后一个子序列的左边界（不含）在第i-1个到第j-1个元素之间游走，进而更新dp[i][j]为最小值。
                {
                    int val = max(dp[i - 1][k], int(sums[j] - sums[k]));
                    dp[i][j] = min(val, dp[i][j]);
                }
            }
        }
        return dp[m][n];
    }
};
