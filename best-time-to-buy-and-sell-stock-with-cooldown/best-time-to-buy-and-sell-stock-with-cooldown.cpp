class Solution {
public:
    vector<int> prices;
    vector<vector<int>> memo;
    int maxProfit(vector<int>& prices) {
        this->prices = prices;
        memo = vector(prices.size(), vector<int>(2, -1));
        return dp(0, 0);
    }
    int dp(int i, int state) {
        if(i >= prices.size()) {
            return 0;
        }
        if(memo[i][state]!=-1) {
            return memo[i][state];
        }
        int ans = dp(i+1, state);
        if(state == 0) {
            ans = max(ans, -prices[i]+dp(i+1, 1));
        } else {
            ans = max(ans, prices[i]+dp(i+2, 0));
        }
        memo[i][state] = ans;
        return ans;
    }
};
