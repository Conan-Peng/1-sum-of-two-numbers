class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //找出不重叠的区间的最多的数目，用总的区间数目减去该数目即得需要移除的最小数目
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int count = 1;
        int x_end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            int start = intervals[i][0];
            if (start >= x_end) 
            {
                count++;
                x_end = intervals[i][1];
            }
        }
        return intervals.size() - count;       
    }
    static bool cmp(const vector<int>& vec1, const vector<int>& vec2){
        return vec1[1] < vec2[1];
    }
    
};
