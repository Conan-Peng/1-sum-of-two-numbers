class Solution {
public:
    string removeKdigits(string num, int k) {
        //递增的数字，只需要从最后面移除，乱序的怎么办呢？
        //维护一个递增栈，像狗熊掰棒子那样，从尾部插入元素，每插入一次都要比较当前元素的值是不是小于原来的尾部元素
        //如果小于，那么将原来的尾部元素弹出再插入，否则直接插入，一直重复k次这种操作
        string res = "";
        int remain = num.size() - k;
        for (char c : num)
        {
            while (k && !res.empty() && c < res.back())//提到贪心算法就提到狗熊掰棒子
            {
                res.pop_back();
                k--;
            }
            res.push_back(c);//删不删尾部元素都要把c插到尾部
        }
        res.resize(remain);//对于没有删够k位的数字，只保留num.size() - k位；
        while (!res.empty() && res[0] == '0') res.erase(res.begin());
        return res.empty() ? "0" : res;
    }
};
