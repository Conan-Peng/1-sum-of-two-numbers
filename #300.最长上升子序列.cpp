class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //dp[i]表示以nums[i]结尾的所有子序列中的长度的最大值
        //状态转移方程：dp[i] = max(...dp[k] | nums[k] < nums[i]) + 1
        if (nums.empty()) return 0;
        vector<int> dp(nums.size(), 1);
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i]) 
                {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
