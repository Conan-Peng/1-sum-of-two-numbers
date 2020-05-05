/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        //这里使用数组排序中的归并排序演变一下求解。一个重要的问题是怎么找中间节点，用快慢指针可以解决这个问题。
        if (!head || !head->next) return head; 
        ListNode* p1 = head, *p2 = head, *pre = head;//增加pre是为了断开链表
        while (p2 && p2->next)
        {
            pre = p1;
            p1 = p1->next;
            p2 = p2->next->next;
        }
        //注意合并的应该是两个分离的链表，因此要增加操作断开链表
        pre->next = NULL;
        return merge(sortList(head), sortList(p1));
    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(), *cur = dummy;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
        }
        cur->next = l1 ? l1 : l2;
        return dummy->next;
    }
};
