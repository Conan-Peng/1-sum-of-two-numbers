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
    bool isSymmetric(TreeNode* root) {
        //两个队列实现迭代遍历二叉树
        if (!root) return true;
        queue<TreeNode*> p, q;
        p.push(root->left);
        q.push(root->right);
        while(!p.empty() && !q.empty())
        {
            TreeNode* node1 = p.front();//因为是取出节点进行操作，可以定义临时变量存储所取节点，好处在于1.避免频繁调用成员函数浪费时间，2.使代码逻辑更加清晰一目了然，3.避免同时调用多种成员出现调用冲突。
            TreeNode* node2 = q.front();
            if (!node1 && !node2)
            {
                p.pop();
                q.pop();  
                continue;
            }
            
            if (!node1 && node2 || node1 && !node2) return false;
            if (node1->val != node2->val) return false;
            p.push(node1->left);
            p.push(node1->right);
            q.push(node2->right);
            q.push(node2->left);
            p.pop();
            q.pop();
        }
        return true;
    }
};
