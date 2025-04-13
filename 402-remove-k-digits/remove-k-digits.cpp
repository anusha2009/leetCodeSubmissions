class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st; 
        for(char digit : num) {
            while(!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }
            st.push(digit);
        }

        // Remove remaining k digits from the end if necessary
        while(k-- > 0 && !st.empty()) {
            st.pop();
        }

        // Build the result string
        string result;
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());

        // Remove leading zeros
        int nonZero = 0;
        while(nonZero < result.size() && result[nonZero] == '0') {
            nonZero++;
        }
        result = result.substr(nonZero);

        return result.empty() ? "0" : result;
    }
};
