class Solution {
public:
    int mySqrt(int x) {
        //使用牛顿迭代法
        if (x == 0) return x;
        double pre = 0, res = 1;
        while (pre != res)
        {
            pre = res;
            res = (pre + x/pre)/2;
        }
        return int(res);
    }
};
