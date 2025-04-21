class Solution {
public:
    string applySubstitutions(vector<vector<string>>& replacements, string text) {
        for(auto& replacement : replacements)
            dict[replacement[0]] = replacement[1];
        for(auto& [key, value] : dict)
            dfs(key);
        int tIndex = 0, tLen = text.size();
        string res;
        while(tIndex < tLen){
            if(text[tIndex] == '%'){
                string key(1, text[tIndex + 1]);
                res += dict[key];
                tIndex += 3;
            }
            else
                res.push_back(text[tIndex++]);
        }
        return res;
    }
private:
    unordered_map<string, string> dict;
    unordered_set<string> visited;
    string dfs(string key){
        if(visited.find(key) != visited.end())
            return dict[key];
        string replacement = dict[key];
        string curRes;
        int index = 0;
        while(index < replacement.size()){
            if(replacement[index] == '%'){
                string curKey(1, replacement[index + 1]);
                curRes += dfs(curKey);
                index += 3;
            }
            else
                curRes.push_back(replacement[index++]);
        }
        dict[key] = curRes;
        visited.insert(key);
        return curRes;
    } 
};