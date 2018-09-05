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
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        while (head) { v.push_back(head->val); head = head->next; }
        for (int i = 0, j = v.size() - 1; i < j; i++, j--) {
            if (v[i] != v[j]) return false;
        }
        return true;
    }
};
