class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //我看不懂这一题，但我已经不打算看懂了，据网上流传的题解说，最大的矩形应该出现在维护的一个递增栈出现较小值时，该较小值作为触发位
        //此时的最大矩阵应该出现在这个递增栈中所有大于该较小值的Bar围成的矩形
        //注意在末尾压一个虚拟的0以便于：将该虚拟节点作为最后一个触发位，便于考察柱状图的最后一位
        int res = 0;
        stack<int> st;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                int j = st.top(); st.pop();
                res = max(res, heights[j] * (st.empty() ? i : i - st.top() - 1));
            }
            st.push(i);
        }
        return res;
    }
};
