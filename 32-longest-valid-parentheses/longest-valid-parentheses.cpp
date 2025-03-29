class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char, int>> st;
        int count = 0;
        int maxCount = 0;
        for(int i = 0; i<s.size(); i++) {
            if(s[i] == '(') {
                st.push({s[i], i});
            } else if(!st.empty()) {
                pair<char, int> val = st.top();
                st.pop();
                s[i] = '1';
                s[val.second] = '1';
            }
        }
        for(char c : s) {
            if(c == '1') {
                count++;
                maxCount = max(maxCount, count);
            } else {
                count = 0;
            }
        }
        return maxCount;
    }
};