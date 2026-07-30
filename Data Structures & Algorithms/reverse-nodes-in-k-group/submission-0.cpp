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
    ListNode* reverseKGroup(ListNode* head, int k) {
        return recurse(head, k);
    }

    ListNode* recurse(ListNode* head, int k) {
        ListNode* original_head = head;
        ListNode* temp = head;
        int count = 0;
        
        while (temp != nullptr && count < k) {
            ++count;
            temp = temp->next;
        }

        if (count < k) {
            return head;
        }

        count = 0;
        ListNode* head_prev = nullptr;

        while (count < k) {
            temp = head->next;
            head->next = head_prev;
            head_prev = head;

            head = temp;
            ++count;
        }

        // head = 4
        // head_prev = 3
        original_head->next = recurse(head, k);

        return head_prev;
    }
};
