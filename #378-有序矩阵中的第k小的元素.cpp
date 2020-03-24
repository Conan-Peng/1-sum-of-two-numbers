class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //使用priority_queue构建大根堆，堆中只存k个元素
        priority_queue<int> q;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                q.emplace(matrix[i][j]);
                if (q.size() > k) q.pop();
            }
        }
        return q.top();
    }
};
