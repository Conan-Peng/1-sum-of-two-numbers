#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    bool closedShape(vector<vector<int> > board){
        //题目见本库中的图片文件
        //使用深搜的方法
        //从边缘开始扫描，如果有0，则对0的上下左右深搜0，并将搜到的0改为1，此时被包围的0将不会被搜索到
        //再次遍历整个数组，如果还有0，那么返回true，否则返回false
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if ((i == 0 || i == board.size() - 1 || j == 0 || j == board[i].size() - 1) && board[i][j] == 0)
                boardDFS(board, i, j);
            }
        }
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                if (board[i][j] == 0) return true;
        return false;
    }
    void boardDFS(vector< vector<int> >& boa, int i, int j){
        boa[i][j] = 1;
        if (i > 0 && boa[i - 1][j] == 0) boardDFS(boa, i - 1, j);
        if (i < boa.size() - 1 && boa[i + 1][j] == 0) boardDFS(boa, i + 1, j);
        if (j > 0 && boa[i][j - 1] == 0) boardDFS(boa, i, j - 1);
        if (j < boa[i].size() - 1 && boa[i][j + 1] == 0) boardDFS(boa, i, j + 1);
    }
};

int main(){
int row, column;
    cin >> row >> column;
vector<vector<int> > bo(row, vector<int>(column));
    for (int m = 0; m < row; m++)
        for (int n = 0; n < column; n++)
            cin >> bo[m][n];
    for (int m = 0; m < row; m++){
        for (int n = 0; n < column; n++)       
            cout<<bo[m][n]<<' ';
        cout << endl;    
    }   
Solution so;
    bool res = so.closedShape(bo);
    if (res) cout << "True" << endl;
    else cout << "False" <<endl;
    return 0;
}
