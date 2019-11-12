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
        ListNode* cur = new ListNode(0);
        ListNode* dummy = cur;
        int carry = 0;
        while (l1 != NULL || l2 != NULL) {
            int x = (l1 != NULL) ? l1->val : 0;
            int y = (l2 != NULL) ? l2->val : 0;
            int num = x + y + carry;
            carry = num / 10;
            cur->next = new ListNode(num % 10);
            cur = cur->next;
            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;
        }
        if (carry) cur->next = new ListNode(carry);
        return dummy->next;
    }
};
