#include<iostream>
using namespace std;

class Solution {
public:
    double mySqrt(int x) {
        //使用牛顿迭代法
        if (x == 0) return x;
        double pre = 0, res = 1; //注意用double,如果用int因为精度不够会造成死循环
        while (pre != res)
        {
            pre = res;
            res = (pre + x/pre)/2;
        }
        return res;
    }
};

int main(){
    Solution so;
    cout << so.mySqrt(8) << endl;
    double n = 2.82843 * 2.82843;
    cout << n;
}
