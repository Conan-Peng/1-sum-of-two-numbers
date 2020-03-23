#include<iostream>
using namespace std;

//使用等差数列求和公式，按数列长度由小到大，求出满足条件的首项
//如果首项小于0，则进入下一循环，直到超出100

int main(){
    int N, L;
    cin >> N >> L;
    for (int i = L; i <= 100; i++)
    {
        int a0 = (2*N + i - i*i)/(2*i);
        if (a0 < 0 || (2*N + i - i*i)%(2*i)) continue; //首项小于0或者不能整除则进入下次循环
        for (int j = 0; j < i - 1; j++)
        {
            cout << a0 + j << ' ';
        }
        cout << a0 + i - 1;
        return 0;
    }
    cout << "No";
    return 0;
}
