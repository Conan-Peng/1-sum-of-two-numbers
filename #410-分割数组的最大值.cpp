class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        //使用二分法，类似于网络切片问题
        //1.切子数组最多切成n块，此时各自和的最大值最小为所有元素的最大值，注意题目对m自我设限，不妨碍我们的假设
        //2.最少切成1块，此时各自和的最大值最小为所有元素之和
        //那么最后要输出的值一定在上面两个值之间，用二分查找法
        //二分查找的判断条件会随切几块而变化，如果切的块数大于m，说明假定值太小了，要升高假定值，否则要切很多刀才合题，
        //如果切的块数小于等于m,说明随便切几刀就合题了，可能是假定值定的太大了，尝试减小假定值。
        long left = 0, right = 0; //long防止加和导致越界
        for (int i = 0; i < nums.size(); i++)
        {
            left = max(int(left), nums[i]);
            right += nums[i];
        }
        //为了构造左闭右开区间，我们先把最右一种情况排除掉
        if (m == nums.size()) return left;
        //注意，这其实是 ”第一个不小于问题“ 的变形，假定输出目标值已经存在了，虽然我们还不知道他是谁，但是我们可以找到第一个不小于他的数
        //也就是说我们要找的值不能比他更小了！
        while (left < right)
        {
            long mid = left + (right - left)/2; //注意，这里如果用（left + right)/2可能会造成溢出如果左右端点都很大的话
            if(judgeTarget(nums, mid, m)) left = mid + 1; //假定值太小要右边查找
            else right = mid; //假定值太大要左边查找
        }
        return int(right);

    }
    bool judgeTarget(vector<int> nums, long mid, int m){
        long cur = 0;
        int cnt = 1;//子数组计数
        for (int j = 0; j < nums.size(); j++)
        {
            cur += nums[j];
            if (cur > mid) 
            {
                cur = nums[j];
                cnt++;
                if (cnt > m) return true;
            }
        }
        return false;
    }
};
