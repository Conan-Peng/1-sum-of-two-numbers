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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    TreeNode* buildTree(vector<int>& inorder, int ileft, int iright, vector<int>& postorder, int pleft, int pright){
        if (ileft > iright || pleft > pright)
        {
            return NULL;
        }
        int i;
        for (i = ileft; i <= iright; i++)
        {
            if (inorder[i] == postorder[pright]) break;
        }
        TreeNode* cur = new TreeNode(postorder[pright]);
        cur->left = buildTree(inorder, ileft, i - 1, postorder, pleft, pleft + i - 1 - ileft);
        cur->right = buildTree(inorder, i + 1, iright, postorder, pright - iright + i, pright - 1);
        return cur;
    }
};
