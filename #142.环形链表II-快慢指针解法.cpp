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
//快指针走的距离是慢指针的两倍，而第一次相遇时快指针比慢指针多走了一个环，
//因此走一个环的距离等于从起点走到第一次相遇点的距离。这两个距离同时减去从环起点到第一相遇点的距离之后仍然相等
//因此慢指针从链表起点开始走，快指针从第一相遇点开始走，每次都只走一步，他们下一次一定在环形的起点相遇。
    ListNode *detectCycle(ListNode *head) {
        ListNode* p1 = head, *p2 = head;
        while (p2 && p2->next)
        {
            p1 = p1->next;
            p2 = p2->next->next;
            if (p1 == p2) break;
        }
        if (!p2 || !p2->next) return NULL;
        p1 = head;
        while (p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};
