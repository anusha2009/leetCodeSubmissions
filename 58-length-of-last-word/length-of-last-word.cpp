class Solution {
public:
    int lengthOfLastWord(string s) {
        
        queue<char> str ;
        for(int i=s.size()-1 ; i>=0 ; --i)
        {
            if(s[i]!=' ')
            {
                str.push(s[i]);
            }
            else if(str.size()>0 && s[i]==' ')
            {
                break;
            }
        }
      
        return str.size();    
    }
};