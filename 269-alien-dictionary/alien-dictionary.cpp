class Solution {
public:
    string alienOrder(vector<string>& words) {
        // Step 0: Create data structures and find all unique letters.
        unordered_map<char, vector<char>> adjList;
        unordered_map<char, int> counts;
        for (string word : words) {
            for (char c : word) {
                counts[c] = 0;
                adjList[c] = vector<char>();
            }
        }

        // Step 1: Find all edges.
        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];
            // Check that word2 is not a prefix of word1.
            if (word1.size() > word2.size() &&
                word1.substr(0, word2.size()) == word2) {
                return "";
            }
            // Find the first non match and insert the corresponding relation.
            for (int j = 0; j < min(word1.size(), word2.size()); j++) {
                if (word1[j] != word2[j]) {
                    adjList[word1[j]].push_back(word2[j]);
                    counts[word2[j]]++;
                    break;
                }
            }
        }

        // Step 2: Breadth-first search.
        string sb = "";
        queue<char> queue;
        for (auto item : counts) {
            if (item.second == 0) {
                queue.push(item.first);
            }
        }
        while (!queue.empty()) {
            char c = queue.front();
            queue.pop();
            sb += c;
            for (char next : adjList[c]) {
                counts[next]--;
                if (counts[next] == 0) {
                    queue.push(next);
                }
            }
        }

        if (sb.size() < counts.size()) {
            return "";
        }
        return sb;
    }
};