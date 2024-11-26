class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i=0; i<s.size(); ++i){
            char ch=s[0];
            s.erase(s.begin());
            s.push_back(ch);
            if(s==goal){
                return true;
            }
        }
        return false;
    }
};