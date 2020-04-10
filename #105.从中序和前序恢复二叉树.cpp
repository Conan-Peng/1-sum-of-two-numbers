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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    //先利用先序性质知道根节点是第一个值， 然后对左右子树有相同性质，递归恢复
    TreeNode* buildTree(vector<int>& preorder, int pleft, int pright, vector<int>& inorder, int ileft, int iright){
        if (pleft > pright || ileft > iright) return NULL;//递归终止条件
        int i;
        for (i = ileft; i <= iright; i++)
        {
            if (preorder[pleft] == inorder[i]) break;
        }
        TreeNode* cur = new TreeNode(preorder[pleft]);
        cur->left = buildTree(preorder, pleft + 1, pleft + i - ileft, inorder, ileft, i - 1);
        cur->right = buildTree(preorder, pright -iright + i + 1, pright, inorder, i + 1, iright);
        return cur;
    }
};
