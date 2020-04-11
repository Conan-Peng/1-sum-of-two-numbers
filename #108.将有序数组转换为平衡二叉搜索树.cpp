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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //由BST的中序遍历是有序数组，而且该BST是平衡的可知，有序数组的中间节点是平衡二叉搜索树的根节点，左右两侧的中间节点分别是左右子树的根节点，依次类推
        return sortedArrayToBST(nums, 0, nums.size());
    }
    TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right){
        if (left >= right) return NULL;
        int mid = left + (right - left)/2;
        TreeNode* cur = new TreeNode(nums[mid]);
        cur->left = sortedArrayToBST(nums, left, mid);
        cur->right = sortedArrayToBST(nums, mid + 1, right);
        return cur;
    }
};
