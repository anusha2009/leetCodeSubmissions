class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> map;
        for(auto& path : paths) {
            map[path[0]] = path[1];
        }
        for(auto& path : paths) {
            if(map.find(path[1]) == map.end()) {
                return path[1];
            }
        }
        return "";
    }
};