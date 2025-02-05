class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> result;
        for(auto& str : strs) {
            // Build the frequency array
            vector<int> freq(26, 0);
            for (char c : str) {
                freq[c - 'a']++;
            }
            
            // Convert freq to a key, e.g. "2#0#1#..." for each of the 26 counts
            // There's many ways; as long as it uniquely represents the freq
            string key;
            for (int count : freq) {
                key += to_string(count) + "#";
            }
            map[key].push_back(str);
        }
        for(auto& m : map) {
            result.push_back(m.second);
        }
        return result;

    }
};

