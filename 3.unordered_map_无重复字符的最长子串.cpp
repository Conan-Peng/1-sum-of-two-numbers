class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, left = -1;
        unordered_map<char, int> m;//定义一个hashmap，存储字符和其映射的最新位置
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (m.count(s[i]) && m[s[i]] > left)//当前字符已经建立映射，且该映射在窗口内时，更新窗口左端点为当前字符的映射位置
            {
                left = m[s[i]];
            }
            m[s[i]] = i;//更新当前字符的映射位置为最新位置；
            res = max(res, i - left);
        }
        return res;
    }
};
