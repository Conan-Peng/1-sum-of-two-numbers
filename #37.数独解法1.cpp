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
    bool isValidSudoku(vector<vector<char> > board, char k, int row, int col) {
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == k) return false;
            if (board[row][i] == k) return false;
        }
        int leftr = row - row % 3, leftc = col - col % 3; //定位到这个元素所在宫的左上角
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[leftr + i][leftc + j] == k) return false;
            }
        } 
        return true;
    }
};
