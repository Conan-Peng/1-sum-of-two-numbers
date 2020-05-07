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
        //二叉树遍历方法的变形，可以把二叉树复制一下作为虚拟根节点的右子树，原二叉树作为左子树，
        //根左右遍历一下，同时根右左遍历一下，看看每次遍历到的值是否相等
        return isSymmetric(root, root);
    }
    bool isSymmetric(TreeNode* root1, TreeNode* root2){
        if (!root1 && !root2) return true;
        else if (!root1 || !root2) return false;
        else if (root1->val != root2->val) return false;
        return isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);
    }

};
