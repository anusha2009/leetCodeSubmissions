class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        unordered_set<char> numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

        string res;
        for(auto& c : s) {
            if(numbers.find(c)!=numbers.end()) {
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