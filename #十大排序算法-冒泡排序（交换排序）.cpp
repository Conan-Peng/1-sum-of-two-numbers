#include<iostream>
#include<vector>

using namespace std;

//将小的沉底
void bubbleSort(vector<int>& a){
    for (int i = 0; i < a.size() - 1; i++)
        for (int j = a.size() - 1; j > i; j--)
            if (a[j] < a[j - 1]) swap(a[j], a[j - 1]);//逆序就调整
}

int main()
{
    int c[8] = {1,3,4,5,2,1,4,5};
	vector<int> A(c, c+8);
    bubbleSort(A);
	for (int b = 0; b < A.size(); b++)
	{
		cout << A[b] << " ";
	}
    return 0;
}
