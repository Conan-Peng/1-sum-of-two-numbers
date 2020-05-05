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
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
        unordered_set<ListNode*> st;
        ListNode* p = head;
        while (p && p->next)
        {
            if (st.count(p)) return p;
            st.insert(p);
            p = p->next;           
        }
        return NULL;
    }
};
