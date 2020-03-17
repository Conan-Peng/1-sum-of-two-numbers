class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //搜索网格中是否有1，每次有1，就深搜该1所处的整片连通区域并把所有的1置为0，并把结果递增1
        int res = 0; 
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1') 
                {
                    gridDFS(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
    void gridDFS(vector<vector<char>>& grid, int i, int j){
        grid[i][j] = '0';
        if (i > 0 && grid[i - 1][j] == '1') gridDFS(grid, i - 1, j);
        if (i < grid.size() - 1 && grid[i + 1][j] == '1') gridDFS(grid, i + 1, j);
        if (j > 0 && grid[i][j - 1] == '1') gridDFS(grid, i, j - 1);
        if (j < grid[i].size() - 1 && grid[i][j + 1] == '1') gridDFS(grid, i, j + 1);
    }
};
