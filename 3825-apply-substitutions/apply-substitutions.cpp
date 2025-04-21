class Solution {
public:
    string applySubstitutions(vector<vector<string>>& replacements, string text) {
        unordered_map<string, string> replacementsMapping;

        for(auto replacement: replacements) 
            replacementsMapping[replacement[0]] = replacement[1];

        for(int i = 0; i < text.size();) {
            string key(1, text[i]);
            if(text[i] == '%') text.erase(i, 1);
            else if(replacementsMapping.find(key) != replacementsMapping.end()) {
                text.erase(i, 1);
                text.insert(i, replacementsMapping[key]);
            } else ++i;
        }

        return text;
    }
};