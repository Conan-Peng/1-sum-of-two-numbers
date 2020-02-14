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
        vector<int> res;
        postorder(root, res);
        return res;
    }
    void postorder(TreeNode* root, vector<int>& res){
        if (!root) return;
        if (root->left) postorder(root->left, res);
        if (root->right) postorder(root->right, res);
        res.push_back(root->val);
    }
};
