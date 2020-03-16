class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //左指针从0开始遍历，右指针每次遍历增加的值都递增1
        //遍历的次数为元素的个数
        //每次遍历都选择区间范围内所有元素中最小的值，乘以长度，比较是否比上一次的结果大
        int res;
        if (heights.empty()) return res = 0;
        res = *max_element(heights.begin(), heights.end());
        int k = 1, n;
        for (int i = 0; i < heights.size(); i++)
        {    
            for (int l = 0, j = l + k; j < heights.size(); j++, l++)
            {
                n = *min_element(heights.begin() + l, heights.begin() + j + 1);
                res = max(res, n * (j - l + 1));
            }
            k++;
        }
        return res;
    }
};
