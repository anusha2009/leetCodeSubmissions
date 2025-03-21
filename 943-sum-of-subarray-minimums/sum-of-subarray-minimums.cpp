class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = 1000000007;
        stack<int> st;
        long sum = 0;
        for(int i = 0; i<=arr.size(); i++) {
            while(!st.empty() && (i==arr.size() || arr[st.top()]>=arr[i])) {
                int mid = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int right = i;
                long count = (mid - left) * (right - mid) % MOD;
                sum += (count * arr[mid]) % MOD;
                sum %= MOD;
            }
            st.push(i);
        }
        return (int) (sum);
    }
};