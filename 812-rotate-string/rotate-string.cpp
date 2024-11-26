class Solution {
public:
    bool rotateString(string s, string goal) {
        bool flag=false;
        for(int i=0; i<s.size(); ++i){
            char ch=s[0];
            s.erase(s.begin());
            s.push_back(ch);
            if(s==goal){
                flag=true;
                break;
            }
        }
        return flag;
    }
};