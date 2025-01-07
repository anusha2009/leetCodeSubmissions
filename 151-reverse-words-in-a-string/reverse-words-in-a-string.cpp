class Solution {
public:
    string reverseWords(string s) {
        stack<string> stack;
        string output;
        for(int i=0;i<s.length();i++){
            while(s[i]==' ' && i<s.length()) {
                i++;
            }
            string newString;
            while(s[i]!=' ' && i<s.length()) {
                newString = newString + s[i];
                i++;
            }
            if (newString.size() > 0) {
                stack.push(newString);
            }
        }
        while(!stack.empty()) {
            string st = stack.top();
            stack.pop();
            output = output + st;
            if(!stack.empty()) {
                output = output + " ";
            }
        }
        return output;

        
    }
};