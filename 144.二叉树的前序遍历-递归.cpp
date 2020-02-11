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
        vector<int> res;
        preorder(root, res);
        return res;
    }
    void preorder(TreeNode* root, vector<int>& res)
    {
        if (!root) return;
        res.push_back(root->val);
        if (root->left) preorder(root->left, res);
        if (root->right) preorder(root->right, res);
    }
};
