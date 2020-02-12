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
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode* t = s.top(); s.pop();
            res.push_back(t->val); 
            if (t->right) s.push(t->right);
            if (t->left) s.push(t->left);
        }
        return res;
    }
};
