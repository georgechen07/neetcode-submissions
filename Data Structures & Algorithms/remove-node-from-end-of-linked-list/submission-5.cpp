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
        
        if (ahead == nullptr) {
            return head->next;
        }

        while (1) {
            ahead = ahead->next;
            if (ahead == nullptr) {
                curr->next = curr->next->next;
                break;
            }
            curr = curr->next;
        }

        return head;
    }
};
