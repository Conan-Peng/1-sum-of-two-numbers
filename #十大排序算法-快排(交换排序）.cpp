#include<iostream>
#include<vector>

using namespace std;

class Qsort{
public:
    void quickSort(vector<int>& a, int leftEnd, int rightEnd){
        if (leftEnd >= rightEnd) return;

        int pivot = a[leftEnd];
        int leftCursor = leftEnd; //左开右闭区间，最左边的是支点取不到。
        int rightCursor = rightEnd + 1;//警醒！一般编译通过的运行异常都是--指针指向未知空间！

        while(true)
        {
            do
            {
                leftCursor++;
            } while (a[leftCursor] < pivot); //左边却不小于支点的索引
            do
            {
                rightCursor--;
            } while (a[rightCursor] > pivot); //右边却不大于支点的索引
            
            if (leftCursor >= rightCursor) break;
            swap(a[leftCursor], a[rightCursor]); //交换
        }
        //放置支点
        a[leftEnd] = a[rightCursor];
        a[rightCursor] = pivot;

        //对左右数段分别快排
        quickSort(a, leftEnd, rightCursor - 1);
        quickSort(a, rightCursor + 1, rightEnd);
    }
};

int main()
{
    int c[8] = {1,3,4,5,2,1,4,5};
	vector<int> A(c, c+8);
    Qsort qs;
	qs.quickSort(A, 0, A.size() - 1);
	for (int b = 0; b < A.size(); b++)
	{
		cout << A[b] << " ";
	}
    return 0;
}
