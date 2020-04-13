class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        //找对角顶点，遍历所有可能情况，更新矩形面积为较小值
        int res = INT_MAX;
        unordered_map<int, unordered_set<int> > mp; //以横坐标为键值，纵坐标为映射值装入hashmap
        for (auto point : points)
        {
            mp[point[0]].insert(point[1]);
        }
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = i + 1; j <points.size(); j++)
            {
                if (points[i][0] == points[j][0] || points[i][1] == points[j][1]) continue;//跳过非对角顶点
                if (mp[points[i][0]].count(points[j][1]) && mp[points[j][0]].count(points[i][1])) 
                //应该存在一点，它的横坐标等于原顶点的横坐标，纵坐标等于对顶点的纵坐标
                //还应该存在一点，它的横坐标等于对顶点的横坐标，纵坐标等于原顶点的纵坐标
                {
                    res = min(res, abs(points[i][0] - points[j][0]) * abs(points[i][1] - points[j][1]));
                }
            }
        }
        return res == INT_MAX ? 0 : res;

    }
};
