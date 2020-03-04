class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        //对于递增数字，关键是从后向前，找到“最后一个“，”不满足值递增的位置”，记录下该位置后将该位置前一位的数字减一，并将该位置及以后的位置置为9
        //要找到最后一个值升高的位置就要遍历全部字符，这里可以用to_string函数，和stoi函数。
        string str = to_string(N);
        int n = str.size(), flag = n;
        for (int i = n - 1; i > 0; i--)
        {
            if (str[i] >= str[i - 1]) continue;
            str[i - 1]--;
            flag = i;
        }
        for (int i = flag; i < n; i++)
        {
            str[i] = '9';
        }
        return stoi(str);
    }
};
