/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;

        int sum = curr1->val + curr2->val;
        int carry = 0;

        if (sum >= 10) {
            carry = 1;
            sum -= 10;
        }

        ListNode* res = new ListNode(sum);
        ListNode* res_curr = res;

        curr1 = curr1->next;
        curr2 = curr2->next;

        while (curr1 != nullptr && curr2 != nullptr) {
            int sum = curr1->val + curr2->val + carry;
            res_curr->next = new ListNode(sum % 10);
            res_curr = res_curr->next;
            if (sum >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }

            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        while (curr1 != nullptr) {
            int sum = curr1->val + carry;
            res_curr->next = new ListNode(sum % 10);
            res_curr = res_curr->next;
            if (sum >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }

            curr1 = curr1->next;
        }

        while (curr2 != nullptr) {
            int sum = curr2->val + carry;
            res_curr->next = new ListNode(sum % 10);
            res_curr = res_curr->next;
            if (sum >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }

            curr2 = curr2->next;
        }

        if (carry == 1) {
            res_curr->next = new ListNode(1);
        }

        return res;
    }
};
