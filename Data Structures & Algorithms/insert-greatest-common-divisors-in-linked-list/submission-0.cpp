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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        auto curr = head;
        while (curr->next != nullptr) {
            auto lhs = curr->val;
            auto rhs = curr->next->val;
            int gcd = 1;
            for (int i = 2; i <= min(lhs, rhs); ++i) {
                if (lhs % i == 0 && rhs % i == 0) {
                    gcd = i;
                }
            }
            curr->next = new ListNode(gcd, curr->next);
            curr = curr->next->next;
        }

        return head;
    }
};