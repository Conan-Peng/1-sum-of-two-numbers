class Solution {
public:
    int mySqrt(int x) {
        //使用二分查找法，搜索从0到x-1的x个数中平方和不大于x的最后一个数
        //此处使用寻找第一个大于目标值的二分查找的模板，回退一位即得到最后一个不大于
        //在此处下标等于元素本身
        int left = 0, right = x;
        if (x <= 1) return x;
        while (left < right)
        {
            int mid = left + (right - left)/2;
            if (mid <= x/mid) //此处因为mid的平方溢出所以改为除法
            left = mid + 1;
            else
            right = mid;
        }
        return right - 1;
    }
};
