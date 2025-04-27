class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> map1;
        map<string, char> map2;
        int i=0;
        int j=0;
        s.push_back(' ');
        while(i<pattern.length() && j<s.length()) {
            char p=pattern[i];
            string sub;
            while(s[j]!=' ') {
                    sub += s[j];
                    j++;
            }
            if(map1.find(p) == map1.end() && map2.find(sub) == map2.end()) {
                map1[p]=sub;
                map2[sub]=p;
            }
            else if(map1[p]!=sub && map2[sub]!=p) {
                return false;
            }
            i++;
            j++;
            if((i==pattern.length() && j<s.length()) || (j==s.length() && i<pattern.length())) {
                return false;
            }
            
        }
        return true;
        
    }
};