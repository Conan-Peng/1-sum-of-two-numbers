class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //判断是否可以使用动规的方法，可以遍历整个数组，找到以每个元素结尾的所有子序列的和的最大值，
        //而当前元素的待求最大值又可以由当前元素值,加或者不加前一个元素的待求最大值，两者之间的较大值求出，存在overlap，因此可以使用动规，因此使用动规
        //dp[i]表示以i结尾的所有子序列和的最大值，递推式为：dp[i] = max(dp[i - 1] + nums[i], nums[i])
        vector<int> dp(nums);
        int res = dp[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};
