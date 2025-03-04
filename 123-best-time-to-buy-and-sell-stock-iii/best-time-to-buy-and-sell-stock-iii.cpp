class Solution {
public:
    vector<int> prices;
    vector<vector<vector<int>>> memo;
    int maxProfit(vector<int>& prices) {
        this->prices = prices;
        int k = 2;
        memo = vector(prices.size(), vector(2, vector(k + 1, -1)));
        
        return dp(0, 0, k);
    }
    
    int dp(int i, int holding, int remain) {
        if (i == prices.size() || remain == 0) {
            return 0;
        }
        
        if (memo[i][holding][remain] != -1) {
            return memo[i][holding][remain];
        }
        
        int ans = dp(i + 1, holding, remain);
        if (holding == 1) {
            ans = max(ans, prices[i] + dp(i + 1, 0, remain - 1));
        } else {
            ans = max(ans, -prices[i] + dp(i + 1, 1, remain));
        }
        
        memo[i][holding][remain] = ans;
        return ans;
    }
};

