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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = new ListNode();
        ListNode* head = res;

        if (lists.size() == 0) {
            return nullptr;
        }

        // start of loop
        while (true) {
            int index = 0;

            for (int i = 1; i < lists.size(); ++i) {
                if (lists[i] != nullptr && (lists[index] == nullptr || lists[i]->val < lists[index]->val)) {
                    index = i;
                }
            }

            if (index == 0 && lists[0] == nullptr) {
                break;
            }

            res->next = lists[index];
            res = res->next;
            lists[index] = lists[index]->next;
        }
        // end of loop

        return head->next;
    }
};
