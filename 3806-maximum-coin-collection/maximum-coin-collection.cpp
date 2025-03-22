class Solution {
public:
    vector<vector<vector<long long>>> memo;
    vector<int> lane1;
    vector<int> lane2;
    long long maxCoins(vector<int>& lane1, vector<int>& lane2) {
        this->lane1 = lane1;
        this->lane2 = lane2;
        memo = vector(2, vector(lane2.size(), vector<long long>(3, -1)));
        long long result = INT_MIN;
        for(int i = 0; i<lane1.size(); i++) {
            result = max(result, max(dp(0, i, 0), dp(1, i, 1)));
        }
        return result;
    }
    long long dp(int lane, int i, int switches) {
        if(i>=lane1.size()) {
            return 0;
        }
        if(memo[lane][i][switches]!=-1) {
            return memo[lane][i][switches];
        }
        long long ans = 0;
        long long coins = 0;
        if(lane == 0) {
            ans += lane1[i];
        } else {
            ans += lane2[i];
        }
        if(switches<2) {
            coins = ans + max(dp(lane, i+1, switches), dp(!lane, i+1, switches+1));
        } else {
            coins = ans + dp(lane, i+1, switches);
        }
        memo[lane][i][switches] = max(ans, coins);
        return memo[lane][i][switches];
    }
};