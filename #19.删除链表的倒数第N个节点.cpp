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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* vhead = new ListNode();
        vhead->next = head;
        ListNode* p1 = vhead, *p2 = vhead;
        for (int i = 0; i < n; i++)
        {
            p2 = p1->next;
            p1 = p2;
        }
        p1 = vhead;
        while (p2->next != NULL)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = p1->next->next;
        return vhead->next;
    }
};
