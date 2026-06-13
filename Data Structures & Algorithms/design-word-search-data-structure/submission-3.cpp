class WordDictionary {
public:
    WordDictionary* children[26];
    bool end;
    
    WordDictionary() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        end = false;
    }
    
    void addWord(string word) {
        WordDictionary* node = this;

        for (char c : word) {
            if (!node->children[c - 'a']) {
                node->children[c - 'a'] = new WordDictionary;
            }
            node = node->children[c - 'a'];
        }
        node->end = true;
    }
    
    bool search(string word) {
        return this->search(word, 0, this);

    }

    bool search(string word, int index, WordDictionary* node) {
        if (node->end == true && index == word.size()) {
            return true;
        } else if (index == word.size()) {
            return false;
        } else if (word[index] == '.') {
            bool check = false;
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != nullptr && node->search(word, index + 1, node->children[i])) {
                    return true;
                }
            }
            return false;
        } else if (!node->children[word[index] - 'a']) {
            return false;
        } else {
            return node->search(word, index + 1, node->children[word[index] - 'a']);
        }
    }
};
