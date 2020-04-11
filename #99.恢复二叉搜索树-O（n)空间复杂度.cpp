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
    void recoverTree(TreeNode* root) {
        //中序遍历一下，把节点存到一个一维数组里，再把值存到另一个一维数组里，把值sort一下回填到节点数组里
        //这是空间复杂度O(n)的解法
        
        vector<TreeNode*> list;
        vector<int> vals;
        helper(root, list, vals);
        sort(vals.begin(), vals.end());
        for (int i = 0; i < list.size(); i++)
        {
            list[i]->val = vals[i];
        }
    }
    void helper(TreeNode* root, vector<TreeNode*>& list, vector<int>& vals)
    {
        if (!root) return;
        helper(root->left, list, vals);
        list.push_back(root);
        vals.push_back(root->val);
        helper(root->right, list, vals);
    }
};
