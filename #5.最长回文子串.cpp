class Solution {
public:
    string longestPalindrome(string s) {
        //dp[i][j]表示区间i~j内字符串是否为回文，有三种情况，当i==j时，dp[i][j]一定为回文，当i!=j时，如果j-i == 1,那么当s[i]==s[j]时dp[i][j]才为真
        //如果j-i > 1, 那么当dp[i+1][j-1]为真且s[i]==s[j]时dp[i][j]才为真
        if (s.empty()) return s;
        vector<vector<int> > dp(s.size(), vector<int>(s.size(), false));
        int li = 0, lj = 0;
        for (int i = 0; i < s.size(); i++)
        {
            dp[i][i] = true;
        }
        for (int len = 1; len < s.size(); len++)
        {
            for (int i = 0; i + len < s.size(); i++)
            {
                int j = i + len;
                if (len == 1) 
                {
                    if (s[i] == s[j])
                    {
                        dp[i][j] = true;
                        if (j - i > lj - li)
                        {
                            li = i;
                            lj = j;
                        }
                    }
                    continue;
                }
                else if (dp[i+1][j-1] && s[i] == s[j])
                {
                   dp[i][j] = true;  
                   if (j - i > lj - li)
                   {
                       li = i;
                       lj = j;
                   }
                } 
            }
        }
        string str;
        for (int i = li; i <= lj; i++)
        {
            str.push_back(s[i]);
        }
        return str;
    }
};
