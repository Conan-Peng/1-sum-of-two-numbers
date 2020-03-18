#include<iostream>
#include<vector>

using namespace std;

//选择排序--先找出最小元素，把它放在第0个位置, 再在剩下的元素里找到最小的元素放在第1个位置， 以此类推
void selectionSort(vector<int>& a){
    for (int i = 0; i < a.size() - 1; i++)
    {
        int j = i;
        for (int k = i + 1; k < a.size(); k++)
        {
            if (a[k] < a[j]) j = k;
        }
        swap(a[j], a[i]);
    }
}

int main()
{
    int c[8] = {1,3,4,5,2,1,4,5};
	vector<int> A(c, c+8);
    selectionSort(A);
	for (int b = 0; b < A.size(); b++)
	{
		cout << A[b] << " ";
	}
    return 0;
}
