/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;
        auto v = unordered_map<Node*, Node*>();

        while (curr != nullptr) {
            Node* created = new Node(curr->val);
            v[curr] = created;

            curr = curr->next;
        }

        for (auto const& [ori, cre] : v) {
            if (ori->next != nullptr) {
                cre->next = v[ori->next];
            }
            if (ori->random != nullptr) {
                cre->random = v[ori->random];
            }
        }

        return v[head];
    }
};
