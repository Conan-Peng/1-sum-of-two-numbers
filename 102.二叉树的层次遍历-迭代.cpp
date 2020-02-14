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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //迭代实现
        //定义一个二维向量vector<vector<int>>,每次向一维向量中存储二叉树的一层，每一层的存储用for循环实现
        //用队列按左右顺序来存储二叉树的一层，每层for循环次数为该层队列中压入的节点的个数
        //每一次进入for循环体，都把队列第一个元素的左右孩子按左右顺序压入队列，并弹出第一个元素，直到弹出该层所有元素。
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q{{root}};
        while(!q.empty())
        {
            vector<int> oneLevel;
            for(int i = q.size(); i > 0; i--)
            {
                TreeNode* t = q.front(); q.pop();
                oneLevel.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            res.push_back(oneLevel);
        }
        return res;
    }
};
