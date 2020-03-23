class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        //找到每个房屋位置所需要的最小半径的最大值
        int res = 0;
        int n = heaters.size();
        sort(heaters.begin(), heaters.end());
        for (auto house : houses)
        {
            //二分法找不小于house的第一个值
            int left = 0, right = n;
            while (left < right)
            {
                int mid = left + (right - left)/2;
                if (house > heaters[mid]) left = mid + 1;
                else right = mid;
            }
            int dist1 = (right == 0) ? INT_MAX : abs(house - heaters[right - 1]);
            int dist2 = (right == n) ? INT_MAX : abs(house - heaters[right]);
            res = max(res, min(dist1, dist2));
        }
        return res;
    }
};
