#include<iostream>
#include<vector>

using namespace std;

//调整索引为rootIndex的元素的位置，直到它大于左右孩子为止。
void adjust(vector<int>& a, int len, int rootIndex){
    int left = 2 * rootIndex + 1; //左孩子
    int right = 2 * rootIndex + 2; //右孩子
    int maxIndex = rootIndex; //假定当前节点为最大

    if (left < len && a[left] > a[maxIndex]) maxIndex = left;
    if (right < len && a[right] > a[maxIndex]) maxIndex = right;

    if (maxIndex != rootIndex)
    {
        swap(a[maxIndex], a[rootIndex]);
        adjust(a, len, maxIndex);//使用递归的方法
    }
}

//1.创建大根堆，2.将根和当前最后一个元素交换位置，并把最后一个元素放在该有的位置 3.排除最后一个元素回到2
//这其实是选择排序，相比于直接选择排序，这里寻找最大值的过程使用了大根堆，使原本O（n^2)的复杂度降到O（nlogn)
void heapSort(vector<int>& a, int size){
    for (int i = size/2 -1; i >= 0; i--) //从最后一个非叶节点向上，创建一个大根堆
    {
        adjust(a, size, i);
    }
    for (int j = size - 1; j > 0; j--)
    {     
        swap(a[0], a[j]);       
        adjust(a, j, 0);
    }
}

int main()
{
    int c[8] = {1,3,4,5,2,1,4,5};
	vector<int> A(c, c+8);
    heapSort(A, A.size());
	for (int b = 0; b < A.size(); b++)
	{
		cout << A[b] << " ";
	}
    return 0;
}
