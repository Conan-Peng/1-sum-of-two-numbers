#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void qSort(vector<int>& vec, int leftEnd, int rightEnd){
    if (leftEnd >= rightEnd)
    {
        return;
    }
    int pivot = leftEnd; //支点
    int leftCursor = leftEnd; //左游标
    int rightCursor = rightEnd + 1; //右游标，左开右闭

    while (true)
    {
        do
        {
            leftCursor++;
        } while (vec[leftCursor] < vec[pivot]);
        do
        {
            rightCursor--;
        } while (vec[rightCursor] > vec[pivot]);
        if (leftCursor >= rightCursor) break;
        swap(vec[leftCursor], vec[rightCursor]);           
    }
    swap(vec[pivot], vec[rightCursor]);//放置支点
    qSort(vec, leftEnd, rightCursor-1);
    qSort(vec, rightCursor+1, rightEnd);
}

int main(){
    vector<int> a{5,3,6,11,432,4,68,6,6,6,7,9};
    qSort(a, 0, a.size() - 1);
    for (auto a0 : a)
    {
        cout << a0 << ' ';
    }
}
