class Solution {
public:
    vector<int> memo;
    vector<int> values;
    int lengthOfLIS(vector<int>& nums) {
        memo = vector<int>(nums.size()+1, -1);
        values = nums;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, dp(i));
        }
        
        return ans;
    }
    int dp(int i) {
        int ans = 1;
        if(memo[i]!=-1) {
            return memo[i];
        }
        for(int j=0; j<i; j++) {
            if(values[i]>values[j]) {
                ans = max(ans, dp(j)+1);
            }
        }
        memo[i] = ans;
        return memo[i];
    }
};