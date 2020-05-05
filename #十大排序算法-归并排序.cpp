#include<iostream>
#include<vector>

using namespace std;

//归并排序其实是合并两个有序数组，
//它用到一个很巧妙的思想，即：数组只有一个节点的时候该数组一定是有序的，因此使用递归，从两个只有一个元素的数组开始合并
void merge(vector<int>& a, int low, int mid, int high){
    int *temp = new int[high - low + 1];
    int i = low; //指向第一个序列的第一个元素的索引
    int j = mid + 1; //指向第二个序列的第一个元素的索引
    int k = 0;//temp数组的索引
    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j]) 
        temp[k++] = a[i++];
        else 
        temp[k++] = a[j++];
    }
    while (i <= mid) //如果第一个序列有剩，就全放到临时数组temp里
    {
        temp[k++] = a[i++];
    }
    while (j <= high) //如果第二个序列有剩，就全放到临时数组temp里
    {
        temp[k++] = a[j++];
    }
    for (i = low, k = 0; i <= high; i++, k++)
    {
        a[i] = temp[k];
    }
    delete []temp;
}

void mergeSort(vector<int>& a, int low, int high){
    if (low >= high) return;
    int mid = (low + high) / 2;
    mergeSort(a, low, mid);
    mergeSort(a, mid + 1, high);
    merge(a, low, mid, high);
}

int main()
{
    int c[8] = {1,3,4,5,2,1,4,5};
	vector<int> A(c, c+8);
    mergeSort(A, 0, A.size() - 1);
	for (int b = 0; b < A.size(); b++)
	{
		cout << A[b] << " ";
	}
    return 0;
}

