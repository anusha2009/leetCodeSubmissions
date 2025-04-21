class Solution {
public:
    void dfs(unordered_map<char, bool>& visited, char currentPlaceholder, unordered_map<char, bool>& placeholders, unordered_map<char, string>& replacement_map, string& ret) {
        if (visited[currentPlaceholder]) return;
        if (currentPlaceholder == '_') {
            ret.push_back('_');
            return;
        }
        visited[currentPlaceholder] = true;
        // if the current placeholder has another placeholder in its replacements
        // go dfs to see that placeholder's replacements
        string replacement = replacement_map[currentPlaceholder];
        for (auto& c : replacement) {
            if (replacement_map.find(c) != replacement_map.end()) {
                dfs(visited, c, placeholders, replacement_map, ret);
            }
            else if (c != '%') {
                ret.push_back(c);
            } else if (c == '%') {
                continue;
            }
        }
        visited[currentPlaceholder] = false;
    }
    string applySubstitutions(vector<vector<string>>& replacements, string text) {
        unordered_map<char, bool> visited;
        // if the replacements contain the placeholder, we need to check if we can form the placeholder
        // build the placeholder list
        unordered_map<char, bool> placeholders;
        unordered_map<char, string> replacement_map;
        string ret;
        string currentPlaceholder;
        for (int i = 0; i < replacements.size(); ++i) {
            char first = replacements[i][0][0];
            string second = replacements[i][1];
            replacement_map[first] = second;
        }
        for (int i = 0; i < text.size(); ++i) {
            // mark the placeholder in map == true
            char curr = text[i];
            if (curr == '_') {
                currentPlaceholder.push_back('_');
            } 
            else if (curr != '%') {
                placeholders[text[i]] = true;
                currentPlaceholder.push_back(text[i]);
            }
        }
        for (auto& c : currentPlaceholder) {
            dfs(visited, c, placeholders, replacement_map, ret);
        }
        return ret;
    }
};