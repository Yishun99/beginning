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
        ListNode* p = head, *q = NULL;
        if (head && head->next) q = head->next->next;
        while (q && q->next) {
            if (p == q)
                return true;
            p = p->next;
            q = q->next->next;
        }
        return false;
    }
};
