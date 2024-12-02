class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        // Since all words are of same length.
        int L = beginWord.size();
        // Dictionary to hold combination of words that can be formed,
        // from any given word. By changing one letter at a time.
        unordered_map<string, vector<string>> allComboDict;
        for (string word : wordList) {
            for (int i = 0; i < L; i++) {
                // Key is the generic word
                // Value is a list of words which have the same intermediate
                // generic word.
                string newWord =
                    word.substr(0, i) + '*' + word.substr(i + 1, L);
                allComboDict[newWord].push_back(word);
            }
        }
        // Queue for BFS
        queue<pair<string, int>> Q;
        Q.push(make_pair(beginWord, 1));
        // Visited to make sure we don't repeat processing same word.
        unordered_map<string, bool> visited;
        visited[beginWord] = true;
        while (!Q.empty()) {
            pair<string, int> node = Q.front();
            Q.pop();
            string word = node.first;
            int level = node.second;
            for (int i = 0; i < L; i++) {
                // Intermediate words for current word
                string newWord =
                    word.substr(0, i) + '*' + word.substr(i + 1, L);
                // Next states are all the words which share the same
                // intermediate state.
                for (string adjacentWord : allComboDict[newWord]) {
                    // If at any point if we find what we are looking for
                    // i.e. the end word - we can return with the answer.
                    if (adjacentWord == endWord) {
                        return level + 1;
                    }
                    // Otherwise, add it to the BFS Queue. Also mark it visited
                    if (!visited[adjacentWord]) {
                        visited[adjacentWord] = true;
                        Q.push(make_pair(adjacentWord, level + 1));
                    }
                }
            }
        }
        return 0;
    }
};