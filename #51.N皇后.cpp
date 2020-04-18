class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        //使用回溯
        vector<vector<string> > res;
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0, res);
        return res;
    }
    void backtrack(vector<string>& board, int row, vector<vector<string> >& res){
        if (row == board.size()) 
        {
            res.push_back(board);
            return;
        }
        for (int col = 0; col < board[row].size(); col++)
        {
            if (!isValid(board, row, col)) continue;
            board[row][col] = 'Q';
            backtrack(board, row + 1, res);
            board[row][col] = '.';
        }
    }
    bool isValid(vector<string> board, int row, int col){
        for (int i = row - 1; i >= 0; i--) //检查上方是否有皇后
        {
            if (board[i][col] == 'Q') return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++)//检查右上方
        {
            if (board[i][j] == 'Q') return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)//检查左上方
        {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }
};
