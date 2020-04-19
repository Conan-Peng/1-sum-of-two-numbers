class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
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
