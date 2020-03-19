#include<iostream>
#include<vector>

using namespace std;

void shellSort(vector<int>& a){
    if (a.size() <= 1) return;
    //将待排序数组分割成多个子序列，对每个子序列进行直接插入排序，一直到每个子序列的长度为1(gap > 0)
    for (int gap = a.size() / 2; gap > 0; gap /= 2)
    {
        //直接插入排序
        for (int i = gap; i < a.size(); i += gap)
        {
            int temp = a[i];
            int j = i - gap;
            while (j >= 0 && temp < a[j]) //注意这里要与临时变量进行比较，a[i]的值可能已经变化
            {
                a[j + gap] = a[j];
                j -= gap;
            }
            a[j + gap] = temp;
        }        
    }
}

int main()
{
    int c[8] = {1,3,4,5,2,1,4,5};
	vector<int> A(c, c+8);
    shellSort(A);
	for (int b = 0; b < A.size(); b++)
	{
		cout << A[b] << " ";
	}
    return 0;
}
