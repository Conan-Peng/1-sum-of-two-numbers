class Solution {
public:
    bool isHappy(int n) {
        //用哈希表来实现，每次判断求出的数是否为1，不是就插入哈希表，是就跳出返回真
        //对于无限循环的情况，判断一旦求出的数和表中已有的元素相同，就跳出循环返回假；
        unordered_set<int> st;
        while (n != 1)
        {
            int sum = 0;
            while (n)
            {
                sum += (n % 10) * (n % 10);//n%10是取出最后一位
                n /= 10;//n/=10是去掉最后一位，就像stack的top,pop函数那样，要牢记。
            }
            if (st.count(sum)) break;
            st.insert(sum);
            n = sum;
        }
        return n == 1;
    }
};
