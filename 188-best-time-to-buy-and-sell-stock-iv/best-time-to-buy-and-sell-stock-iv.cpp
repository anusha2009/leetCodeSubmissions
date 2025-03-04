class Solution {
public:
    vector<int> prices;
    vector<vector<vector<int>>> memo;
    
    int maxProfit(int k, vector<int>& prices) {
        this->prices = prices;
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


//bottom-up

/*

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector(2, vector(k + 1, 0)));
        for (int i = n - 1; i >= 0; i--) {
            for (int remain = 1; remain <= k; remain++) {
                for (int holding = 0; holding < 2; holding++) {
                    int ans = dp[i + 1][holding][remain];
                    if (holding == 1) {
                        ans = max(ans, prices[i] + dp[i + 1][0][remain - 1]);
                    } else {
                        ans = max(ans, -prices[i] + dp[i + 1][1][remain]);
                    }
                    
                    dp[i][holding][remain] = ans;
                }
            }
        }
        
        return dp[0][0][k];
    }
};

*/