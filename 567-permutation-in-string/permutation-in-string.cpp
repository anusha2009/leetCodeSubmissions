class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) {
            return false;
        }
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;
        for(char c : s1) {
            map1[c]++;
        }
        for(int i = 0; i<s1.size(); i++) {
            map2[s2[i]]++;
        }
        if(matches(map1, map2)) {
            return true;
        }
        for(int i = s1.size(); i<s2.size(); i++) {
            map2[s2[i]]++;
            map2[s2[i-s1.size()]]--;
            if (map2[s2[i - s1.size()]] == 0)          // clean up zero count
                map2.erase(s2[i - s1.size()]);
            if(matches(map1, map2)) {
                return true;
            }
        }
        return false;
        
    }
    bool matches(unordered_map<char, int>& map1, unordered_map<char, int>& map2) {
        for (auto& [ch, cnt] : map1) {
            if (map2[ch] != cnt) return false;
        }
        return true;
    }

};