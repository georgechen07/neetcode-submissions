class PrefixTree {
public:
    PrefixTree* childrens[26];
    bool end_of_word;

    PrefixTree() {
        end_of_word = false;
        for (int i = 0; i < 26; i++) {
            childrens[i] = nullptr;
        }
    }

    void insert(string word) {
        PrefixTree* node = this;
        for (char c : word) {
            int index = c - 'a';
            if (!node->childrens[index]) {
                node->childrens[index] = new PrefixTree();
            }
            node = node->childrens[index];
        }
        node->end_of_word = true;
    }
    
    bool search(string word) {
        PrefixTree* node = this;
        for (char c : word) {
            int index = c - 'a';
            if (!node->childrens[index]) {
                return false;
            }
            node = node->childrens[index];
        }
        return node->end_of_word;
    }
    
    bool startsWith(string prefix) {
        PrefixTree* node = this;
        for (char c : prefix) {
            int index = c - 'a';
            if (!node->childrens[index]) {
                return false;
            }
            node = node->childrens[index];
        }
        return true;
    }
};
