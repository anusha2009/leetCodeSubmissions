class Solution {
public:
    vector<int> memo;
    int minCostClimbingStairs(vector<int>& cost) {
        memo = vector<int>(cost.size()+1, -1);
        return dp(cost.size(), cost);
    }
    int dp(int i, vector<int>& cost) {
        if(i<=1) {
            return 0;
        }
        if(memo[i]!=-1) {
            return memo[i];
        }
        memo[i] = min(dp(i-1, cost)+cost[i-1], dp(i-2, cost)+cost[i-2]);
        return memo[i];
    }
};