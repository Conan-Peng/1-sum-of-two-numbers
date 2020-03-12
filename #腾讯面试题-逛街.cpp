#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class solution{
    public:
    vector<int> hangStreet(int n, vector<int> height){
        //使用单调栈，分别获取从右往左看的楼栋，和从左往右看到的楼栋
        vector<int> res, a, b;
        stack<int> s1, s2;
        for (int i = 0; i < n; i++)
        {
            a.push_back(s1.size());
            while (!s1.empty() && s1.top() <= height[i]) s1.pop();
            s1.push(height[i]);                
        }
        for (int j = n-1; j >= 0; j--)
        {
            b.push_back(s2.size());
            while (!s2.empty() && s2.top() <= height[j]) s2.pop();
            s2.push(height[j]); 
        }
        reverse(b.begin(), b.end());
        for (int i = 0; i < n; i++)
        {
            res.push_back(a[i] + b[i] + 1);
        }
        return res;
    }
};

int main(){
    int n;
    vector<int> height(100001);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> height[i];
    vector<int> ans;
    solution so;
    ans = so.hangStreet(n, height);
    for (int i = 0; i < n; i++)
    {
       cout << ans[i] << ' ';
    }
    return 0;    
}
