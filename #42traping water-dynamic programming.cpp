class Solution {
public:
    int trap(vector<int>& height) {
        //每个位置可以接的雨水量其实是 看 它的”左边的最大值“与它的“右边的最大值”之间的“较小值”
        //这个较小值比这个位置的高度大时，这个位置才可以接水，接的水量为较小值与该位置高度的差值。
        //使用动态规划的方法，维护一个dp数组，第一次从左向右遍历，存储每个位置左边的最大值
        //第二次从右向左遍历，存储每个位置右边的最大值
        //在每个位置上判断并加和
        int res = 0, mx = 0, n = height.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++)
        {
            dp[i] = mx;
            mx = max(mx, height[i]);
        }
        mx = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            dp[i] = min(dp[i], mx);
            mx = max(mx, height[i]);
            if (height[i] < dp[i]) res += dp[i] - height[i];
        }
        return res;
    }
};
