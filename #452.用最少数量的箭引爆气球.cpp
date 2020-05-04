class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        //把最大不重叠的区间的数目找出来，只要他们能爆，内部重叠的一定能爆，因此该数目等于最少要使用的箭头数目
        //注意这里不重叠的定义应该是端点也不能重叠，因为题干中说明端点重叠也算重叠。
        if (points.empty()) return 0;
        sort(points.begin(), points.end(), cmp);
        int count = 1;
        int x_end = points[0][1];
        for (int i = 1; i < points.size(); i++)
        {
            int start = points[i][0];
            if (start > x_end) //注意这里不能有等于
            {
                count++;
                x_end = points[i][1];
            }
        }
        return count;
    }
    static bool cmp(const vector<int>& vec1, const vector<int>& vec2){
        return vec1[1] < vec2[1];
    }
};
