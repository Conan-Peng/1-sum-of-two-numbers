class Solution {
public:
    int maxArea(vector<int>& height) {
        //用两个指针从两边向中间搜索，谁小谁移
        int res = 0, i = 0, j = height.size() - 1;
        while (i < j)
        {
            res = max(res, min(height[i], height[j]) * (j - i));
            height[i] < height[j] ? i++ : j--;
        }
        return res;
    }
};
