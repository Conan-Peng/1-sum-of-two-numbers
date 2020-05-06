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
    ListNode* reverseList(ListNode* head) {
        //本题可以用递归实现。递归其实是一种回溯，一步步前进到倒数第二个节点，再一步步返回。每次将向后指的指针改为向前指。
        if (!head || !head->next) return head;//走到最后一个节点的时候递归终止
        ListNode* newHead = reverseList(head->next); //每次向后指递归，newHead是最后一个节点，也是反转后链表的头结点。
        head->next->next = head;//从倒数第二个节点开始往前，建立向前的指针
        head->next = NULL;//断开向后的指针
        return newHead;
    }
};
