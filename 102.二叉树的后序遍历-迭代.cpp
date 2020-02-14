/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        //迭代实现后序遍历
        //后序遍历和前序遍历很相似，可以由前序遍历作简单修改得到。前序是根左右，后序是左右根，因此只需要在前序遍历
        //的代码中压栈时先压左孩子，再压右孩子，这样出栈的顺序就变成右左，总的结果是根右左，这样反向（从向量的前部）压入数据就变成了左右根
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> s{{root}};
        while (!s.empty()) 
        {
            TreeNode* t = s.top(); s.pop();
            res.insert(res.begin(), t->val);
            if (t->left) s.push(t->left);
            if (t->right) s.push(t->right);
        }
        return res;       
    }
};
