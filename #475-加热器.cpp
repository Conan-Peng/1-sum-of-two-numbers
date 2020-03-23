class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        //找到每个房屋位置所需要的最小半径的最大值
        //将两个数组都变为有序的，以便从前向后遍历，前面有合题的，后面就不用找了
        int res = 0;
        int n = heaters.size(), j = 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        for (int i = 0; i < houses.size(); i++)
        {
            int cur = houses[i];
            while (j < n - 1 && abs(cur - heaters[j + 1]) <= abs(cur - heaters[j]))//一直往后找加热器，两个两个地比较，
            //如果后一个加热器到该房子的距离更小，那么把加热器指针后移，一旦不小于等于就直接跳出，因为已经对加热器升序，后面只会更大不会更小，
            //用小于等于是因为最后一个测试用例给错了，把房屋和加热器1522的位置重复了一次，如果用小于会造成i后移了而j会卡在那个没减小的位置无法前进。
            {
                j++;
            }
            res = max(res, abs(cur - heaters[j]));
        }
        return res;
    }
};
