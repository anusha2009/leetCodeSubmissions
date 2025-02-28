class Solution {
public:
    vector<int> memo;
    vector<int> cost;
    int rob(vector<int>& nums) {
        memo = vector<int>(nums.size(), -1);
        cost = nums;
        return dp(nums.size()-1);
    }
    int dp(int i) {
        if(i==0) {
            return cost[0];
        }
        if(i==1) {
            return max(cost[1], cost[0]);
        }
        if(memo[i]!=-1) {
            return memo[i];
        }
        memo[i] = max(dp(i-2)+cost[i], dp(i-1));
        return memo[i];
    }
};