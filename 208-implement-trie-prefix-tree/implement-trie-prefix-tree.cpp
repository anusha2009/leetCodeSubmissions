class TrieNode {
private:
    // R links to node children
    TrieNode* links[26];
    bool isEnd;

public:
    TrieNode() {
        // Initialize all links to null
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
        isEnd = false;
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    TrieNode* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, TrieNode* node) {
        links[ch - 'a'] = node;
    }

    void setEnd() {
        isEnd = true;
    }

    bool isEndOfWord() {
        return isEnd;
    }
};

class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Inserts a word into the trie.
    void insert(const std::string& word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            char currentChar = word[i];
            if (!node->containsKey(currentChar)) {
                node->put(currentChar, new TrieNode());
            }
            node = node->get(currentChar);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        TrieNode* node = searchPrefix(word);
        return node != nullptr && node->isEndOfWord();
    }

    // Search a prefix or whole key in trie and
    // returns the node where search ends
    TrieNode* searchPrefix(const std::string& word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            char curLetter = word[i];
            if (node->containsKey(curLetter)) {
                node = node->get(curLetter);
            } else {
                return nullptr;
            }
        }
        return node;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = searchPrefix(prefix);
        return node != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */