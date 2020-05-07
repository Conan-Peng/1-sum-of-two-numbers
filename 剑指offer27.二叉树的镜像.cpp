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
    TreeNode* mirrorTree(TreeNode* root) {
        //前序遍历一颗二叉树，只要一个节点有子树就交换它的两个子树，递归实现      
        recursively(root);
        return root;
    }
    void recursively(TreeNode* root){
        if (!root) return;
        else if (!root->left && !root->right) return;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        recursively(root->left);
        recursively(root->right);
    }
};
