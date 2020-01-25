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
        if (k <= 2) //数组大小小于等于2时，直接返回所有元素，多此一举在于while判断条件过于简单。
        return k;
        else
        return ++pre;
    }
};
