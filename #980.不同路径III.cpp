class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        //使用回溯和深度优先遍历
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        int cnt = 0, startrow, startcol, res = 0;
        vector<vector<int>> visit(grid);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    cnt++;
                }
                else if (grid[i][j] == 1)
                {
                    startrow = i;
                    startcol = j;
                }
                else if (grid[i][j] == 2)
                {
                    visit[i][j] = 0;
                }
            }
        }
        dfs(visit, grid, startrow, startcol, cnt, 0, res);
        return res;
    }
    void dfs(vector<vector<int>> visit, vector<vector<int>> grid, 
                int startrow, int startcol, int sumCnt, int curCnt, int& res){
        if (grid[startrow][startcol] == 2) 
        {
            if (curCnt == sumCnt + 1)
            res++;
            return;
        }
        if (startrow > 0 && visit[startrow-1][startcol] == 0) 
        {
            visit[startrow-1][startcol] = 1;
            dfs(visit, grid, startrow-1, startcol, sumCnt, curCnt+1, res);
            visit[startrow-1][startcol] = 0;
        }
        if (startrow < visit.size() - 1 && visit[startrow+1][startcol] == 0) 
        {
            visit[startrow+1][startcol] = 1;
            dfs(visit, grid, startrow+1, startcol, sumCnt, curCnt+1, res);
            visit[startrow+1][startcol] = 0;
        }
        if (startcol > 0 && visit[startrow][startcol-1] == 0) 
        {
            visit[startrow][startcol-1] = 1;
            dfs(visit, grid, startrow, startcol-1, sumCnt, curCnt+1, res);
            visit[startrow][startcol-1] = 0;
        }
        if (startcol < visit[0].size() - 1 && visit[startrow][startcol+1] == 0) 
        {
            visit[startrow][startcol+1] = 1;
            dfs(visit, grid, startrow, startcol+1, sumCnt, curCnt+1, res);
            visit[startrow][startcol+1] = 0;
        }
    }
};
