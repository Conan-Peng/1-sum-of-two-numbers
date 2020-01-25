class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //定义一个记数值cnt，初值为1，重复一次即递减1，快指针向前跳1位
        int cnt = 1;
        int pre = 0;//慢指针
        int cur = 1;//快指针
        int k = nums.size();
        while (cur < k)
        {
            if (nums[pre] == nums[cur])
            {
                if (cnt == 0)
                {
                    cur++;
                }
                else
                {
                    nums[++pre] = nums[cur++];
                    cnt--;
                }
            }
            else
            {
                nums[++pre] = nums[cur++];
                cnt = 1;
            }
        }
        return nums.empty() ? 0 : ++pre;
    }
};
