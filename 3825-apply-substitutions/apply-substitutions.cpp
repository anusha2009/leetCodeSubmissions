class Solution {
public:
    // To replace value of type: "%F%%E%"
    string substitute(string &input, unordered_map<string, string> &rawMap) {
        string ans = "";
        for (int i=0; i<input.size(); i++) {
            char ch = input[i];
            if (ch == '%') {
                string resolved = rawMap[string(1,input[i+1])];
                ans += resolved;
                i = i+2; // move to the 2nd%
            } else {
                ans += ch;
            }
        }
        return ans;
    }

    // To replace value of type: "%E%_%F%_%D%"
    string substituteFinalString(string &input, unordered_map<string, string> &rawMap) {
        string ans = "";
        int n = input.size();
        for (int i=0; i<n; i++) {
            char ch = input[i];
            if (ch == '%') {
                string resolved = rawMap[string(1, input[i+1])];
                ans += resolved;
                i = i+3; // move to the _
            }
            if (i < n)
                ans += "_";
        }
        return ans;
    }

    string applySubstitutions(vector<vector<string>>& replacements, string text) {
        unordered_map<string, string> rawMap;
        unordered_map<string, vector<string>> adj;
        unordered_map<string, int> inDegree;

        for (auto& replacement : replacements) {
            string key = replacement[0];
            string val = replacement[1];
            rawMap[key] = val;

            // Parse val for dependencies
            for (int i = 0; i < val.size(); i++) {
                if (val[i] == '%') {
                    i++; // Move to the character;
                    string prerequisite = string(1, val[i]);
                    adj[prerequisite].push_back(key);
                    inDegree[key]++;
                    i++; // Move to the %;
                }
            }
        }

        // Topological sort
        queue<string> q;
        for (auto& pair : rawMap) {
            if (inDegree[pair.first] == 0) {
                q.push(pair.first);
            }
        }

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            for (string& neighbor : adj[curr]) {
                if (--inDegree[neighbor] == 0) {
                    // Replace current placeholder in neighbor's raw string
                    rawMap[neighbor] = substitute(rawMap[neighbor], rawMap);
                    q.push(neighbor);
                }
            }
        }

        // Final replacement in the text
        return substituteFinalString(text, rawMap);
    }
};