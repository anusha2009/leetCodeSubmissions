class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        unordered_map<char, int> map;
        for(int i=0;i<s.length();i++) {
            map[s[i]]++;
        }
        for(int i=0;i<t.length();i++) {
            if(map[t[i]]) {
                map[t[i]]--;
            } else {
                return false;
            }
        }
        for(int i=0;i<s.length();i++) {
            if(map[s[i]]) {
                return false;
            }
        }
        return true;
    }
};