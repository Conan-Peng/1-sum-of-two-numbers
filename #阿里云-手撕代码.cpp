//评测题目: 阿里投资部门的问题，假设我们每次可以投资一个项目，可以最大投资X次不同的项目，
//每个项目的投资的钱不同，假设我们启动资金是Y元，我们有M的投资项目列表代表投资它需要的钱，有N的列表表示纯收益。
//求最大化收益，输出最大收益的钱。请完成你认为时间复杂度最小的解。
// 例子：
// 输入：X=2, Y=0, M=[0,1,1], N=[1,2,3]
// 输出：4
// 解释：1+3 = 4
// 约束：
// 所有的输入都是非负整数。
// M，N列表最大不超过50000，M有可能是乱序的
// 收益最大不超过32位有符号数。

#include<iostream>
#include<vector>
#include<limits.h>
#include<map>
#define t 4

using namespace std;

int investProg(int X, int Y, vector<int>& M, vector<int>& N){
    //用动态规划，二维数组dp[i][j]表示投资前i个项目时，已经投资了j次，获得的最大收益
    //状态转移方程为dp[i][j] = max(dp[i-1][j-1] + N[i-1] - M[i-1], dp[i-1][j]);
    if (M.empty()) return 0;
    //用multimap，使M中的元素自动升序，N中元素相应移动
    multimap<int, int> mm;
    for (int i = 0; i < M.size(); i++)
    {
        mm.insert(pair<int, int>(M[i], N[i]));
    }
    //M已升序排列，N也已经对应移动
    multimap<int, int>::iterator iter = mm.begin();
    if (Y < iter->first) return 0;
    vector<vector<int> > dp(M.size() + 1, vector<int>(X + 1, INT_MIN));
    for (int i = 0; i < M.size() + 1; i++)
    {        
        if (i > 1) iter++;//iter始终指向multimap中下标为i-1的数对
        for (int j = 0; j < X + 1; j++)
        {
            //base case
            if (i == 0 || j == 0) dp[i][j] = 0;
            else 
            {    
                if (dp[i-1][j-1] + Y < iter->first) dp[i][j] = dp[i-1][j]; //前i-1个项目已经投了j-1次,手里的资金还不够投资第i-1个项目时
                else dp[i][j] = max(dp[i-1][j-1] + iter->second, dp[i-1][j]);//第i-1个项目能投，再考虑投不投
            }
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    return dp[M.size()][X];
}

int main(){
    int X = 3, Y = 0;
    int a[t] = {4,1,0,1}, b[t] = {500,2,1,4};
    vector<int> M(a, a+t), N(b, b+t);
    int res = investProg(X, Y, M, N);
    cout << "begin" << endl;
    for (auto a : M) cout << a << ' ';
    cout << endl;
    for (auto a : N) cout << a << ' ';
    cout << endl;
    cout << res << endl;
    return 0;
}
