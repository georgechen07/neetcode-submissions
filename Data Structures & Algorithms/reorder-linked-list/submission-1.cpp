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
    void reorderList(ListNode* head) {
        if (head->next == nullptr) {
            return;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        bool slowGo = false;
        // finds midpoint
        // slow is middle element in odd sized list
        while (fast != nullptr) {
            fast = fast->next;
            if (slowGo) {
                slow = slow->next;
            }
            slowGo = !slowGo;
        }

        // reverses second list
        slowGo = true;
        ListNode* prev = slow;
        ListNode* prev2 = slow;
        do {
            prev2 = prev;
            prev = slow;
            slow = slow->next;
            if (slowGo) {
                prev2->next = nullptr;
                slowGo = false;
            } else {
                prev->next = prev2;
            }
        } while (slow != nullptr);

        ListNode* frontCurr = head;
        ListNode* frontPrev = head;
        ListNode* backCurr = prev;
        ListNode* backPrev = prev;
        while (backCurr != nullptr) {
            frontPrev = frontCurr;
            backPrev = backCurr;

            frontCurr = frontCurr->next;
            backCurr = backCurr->next;

            frontPrev->next = backPrev;
            if (frontCurr == backCurr || frontCurr == backPrev) {
                break;
            }
            backPrev->next = frontCurr;
        }
    }
};
