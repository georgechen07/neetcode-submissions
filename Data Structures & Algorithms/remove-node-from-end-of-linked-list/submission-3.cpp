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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr) {
            return nullptr;
        }
        
        ListNode* curr = head;
        ListNode* ahead = curr;
        for (int i = 0; i < n; ++i) {
            ahead = ahead->next;
        }
        
        while (ahead != nullptr) {
            ahead = ahead->next;
            if (ahead == nullptr) {
                curr->next = curr->next->next;
            }
            curr = curr->next;
        }

        if (curr == head) {
            return head->next;
        }
        return head;
    }
};
