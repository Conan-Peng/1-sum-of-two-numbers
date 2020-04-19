#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char> >& board){
        //使用回溯，路径，选择列表，终止条件
        backtrack(board);        
    }
    bool backtrack(vector<vector<char> >& board){
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] != '.') continue;
                for (char k = '1'; k <= '9'; k++)
                {                  
                    if (!isValidSudoku(board, k, i, j)) continue;
                    board[i][j] = k;
                    if (backtrack(board)) return true;
                    board[i][j] = '.';
                }
                return false;
            }
        } 
        return true;                        
    }
    bool isValidSudoku(vector<vector<char> > board, char k, int i, int j) {
        board[i][j] = k;
        map<int, multiset<char> > rowmp, colmp, gridmp;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                rowmp[i].insert(board[i][j]);//每行元素
                colmp[i].insert(board[j][i]);//每列元素
                gridmp[i/3 * 3 + j/3].insert(board[i][j]); // 第（i,j）个元素属于第【行号（i/3)*3 + 列号（j/3)】个宫
            }
        }        
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.') continue;
                if (rowmp[i].count(board[i][j]) > 1 || colmp[j].count(board[i][j]) > 1 || gridmp[i/3 * 3 + j/3].count(board[i][j]) > 1) 
                return false;
            }
        }
        return true;
    }
};
int main(){
/*
[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],
["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],
[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
*/
    vector<vector<char> > board({
    {'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'},       
                               });
    for (int i = 0; i < 9; i++)
    {
        cout << endl;
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << ' ';
        }

    }

    Solution so;
    so.solveSudoku(board);
    cout << "-----------------------------------" << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << endl;
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << ' ';
        }

    }


    return 0;
}



