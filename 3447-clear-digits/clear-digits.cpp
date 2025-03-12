class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        string res;
        for(auto& c : s) {
            if(isdigit(c)) {
                st.pop();
            } else {
                st.push(c);
            }
        }
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};