// Definition for singly-linked list.
struct ListNode {
    int key;
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x, int y) : key(x), val(y), next(nullptr) {}
    ListNode(int x, int y, ListNode *next) : key(x), val(y), next(next) {}
};


class LRUCache {
public:
    LRUCache(int capacity) {
        this->head = nullptr;
        this->capacity = capacity;
        this->size = 0;
    }
    
    int get(int key) {
        ListNode* curr = this->head;
        if (curr == nullptr) {
            return -1;
        } else if (curr->key == key) {
            return curr->val;
        }

        while (curr->next != nullptr && curr->next->key != key) {
            curr = curr->next;
        }

        if (curr->next == nullptr) {
            return -1;
        } else {
            ListNode* temp = curr->next;
            curr->next = temp->next;
            temp->next = this->head;
            this->head = temp;
            return temp->val;
        }
    }
    
    void put(int key, int value) {
        ListNode* created = new ListNode(key ,value);
        ++size;
        created->next = this->head;
        this->head = created;

        ListNode* curr = created;
        while (curr->next != nullptr && curr->next->key != key && curr->next->next != nullptr) {
            curr = curr->next;
        }

        // curr->next->next = nullptr
        // curr->next = last element of list
        if (curr->next != nullptr && curr->next->key == key) {
            curr->next = curr->next->next;
            --this->size;
        } else if (size > capacity) {
            --this->size;
            curr->next = nullptr;
        }

        cout << "Current List appearance\n";
        ListNode* start = this->head;
        while (start != nullptr) {
            cout << "key: " << start->key << " val: " << start->val << ", ";
            start = start->next;
        }
        cout << '\n';
    }

private:
    ListNode* head;
    int size;
    int capacity;
};
