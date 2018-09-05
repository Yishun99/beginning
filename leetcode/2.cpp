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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, ans;
        ListNode* l3 = new ListNode(0);
        ListNode* tail = l3;
        while (l1 || l2 || carry) {
            ans = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = ans / 10;
            tail->next = new ListNode(ans % 10);
            tail = tail->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return l3->next;
    }
};
