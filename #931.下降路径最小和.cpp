class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        //使用动态规划，以原数组A[i][j]表示到达位置(i,j)的下降路径最小和, 在第一行中，每个位置的元素已经都合规，从第二行开始由于每一行只能选择一个元素，
        //所以只能由上一行进入，每一行从左到右遍历，从右上方进入时也可以，因为右上方也已经计算过了
        //有状态转移方程：A[i][j] = min (A[i-1][j-1], A[i-1][j], A[i-1][j+1]) + A[i][j]
        int res = INT_MAX;
        if (A.size() == 1) 
        for (int a : A[0]) res = min(res, a);
        for (int i = 1; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                int temp = A[i-1][j];
                if (j < A[i].size() - 1) temp = min(temp, A[i-1][j+1]);
                if (j > 0)  temp = min(A[i-1][j-1], temp);            
                A[i][j] += temp;
                if (i == A.size() - 1) res = min(res, A[i][j]);
            }
        }
        return res;
    }
};
