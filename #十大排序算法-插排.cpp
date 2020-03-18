#include<iostream>
#include<vector>

using namespace std;

void insertSort(vector<int>& a, int n){
    if (n <= 1) return;
    for (int i = 1; i < n; i++)
    {
        int temp = a[i];
        int j = i - 1;
        while (j >= 0 && temp < a[j])//不停往前回找，直到临时变量不再小于当前值为止。如果小于，就把当前值后移一位。
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;//找到该临时变量合适的位置后回填该临时变量。
    }
}

int main()
{
    int c[8] = {1,3,4,5,2,1,4,5};
	vector<int> A(c, c+8);
    insertSort(A, A.size());
	for (int b = 0; b < A.size(); b++)
	{
		cout << A[b] << " ";
	}
    return 0;
}
