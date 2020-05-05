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
    bool hasCycle(ListNode *head) {
        //用快慢指针，快指针走两步，慢指针走一步，如果有环，快指针一定会套圈追上慢指针。
        ListNode* p1 = head, *p2 = head;
        while (p2 != NULL && p2->next != NULL)
        {
            p1 = p1->next;
            p2 = p2->next->next;
            if (p1 == p2) return true;
        }
        return false;
    }
};
