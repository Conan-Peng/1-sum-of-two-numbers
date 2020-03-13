class Solution {
public:
    void solve(vector<vector<char>>& board) {
        //采用深度优先搜索的方法
        //从边缘开始扫描，边缘如果有O，就从O开始深搜，将相连的O全部变成其他符号，如P
        //剩下的O就全是被包围的O，现在遍历全部元素把所有的O改为X，将所有的P改为O
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if ((i == 0 || i == board.size() - 1 || j == 0 || j == board[i].size() - 1) && board[i][j] == 'O')
                {
                    boardDFS(board, i, j);
                }
            }
        }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'P') board[i][j] = 'O';
            }
        }
    }
    void boardDFS(vector<vector<char>>& board, int i, int j)
    {
            board[i][j] = 'P';
            if (i > 0 && board[i - 1][j] == 'O') boardDFS(board, i - 1, j);
            if (i < board.size() - 1 && board[i + 1][j] == 'O') boardDFS(board, i + 1, j);
            if (j > 0 && board[i][j - 1] == 'O') boardDFS(board, i, j - 1);
            if (j < board[i].size() - 1 && board[i][j + 1] == 'O') boardDFS(board, i, j + 1);

    }
};
