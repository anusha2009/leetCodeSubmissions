struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool word = false;
};

class WordDictionary {
    TrieNode* trie;

public:
    /** Initialize your data structure here. */
    WordDictionary() { trie = new TrieNode(); }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* node = trie;

        for (char ch : word) {
            if (!node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->word = true;
    }

    /** Returns if the word is in the node. */
    bool searchInNode(string word, TrieNode* node) {
        for (int i = 0; i < word.length(); ++i) {
            char ch = word[i];
            if (!node->children.count(ch)) {
                // If the current character is '.'
                // check all possible nodes at this level
                if (ch == '.') {
                    for (auto x : node->children) {
                        TrieNode* child = x.second;
                        if (searchInNode(word.substr(i + 1), child)) {
                            return true;
                        }
                    }
                }
                // If no nodes lead to answer
                // or the current character != '.'
                return false;
            } else {
                // If the character is found
                // go down to the next level in trie
                node = node->children[ch];
            }
        }
        return node->word;
    }

    /** Returns if the word is in the data structure. A word could contain the
     * dot character '.' to represent any one letter. */
    bool search(string word) { return searchInNode(word, trie); }
};