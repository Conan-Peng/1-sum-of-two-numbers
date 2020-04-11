/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        //用快慢指针找链表的中点，其他操作和有序数组一致
        if (head == NULL) return NULL;
        return sortedListToBST(head, NULL);
    }
    TreeNode* sortedListToBST(ListNode* head, ListNode* tail){
        if (head == tail) return NULL;
        ListNode* fast = head, *slow = head;
        while (fast != tail && fast->next != tail)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* cur = new TreeNode(slow->val);
        cur->left = sortedListToBST(head, slow);
        cur->right = sortedListToBST(slow->next, tail);
        return cur;
    }
};
