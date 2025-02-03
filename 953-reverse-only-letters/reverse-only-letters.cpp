class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i<j) {
            while(!isalpha(s[i]) && i<j) {
                i++;
            }
            while(!isalpha(s[j]) && i<j) {
                j--;
            }
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
        return s;
        
    }
};