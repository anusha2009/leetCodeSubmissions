class Solution {
public:
    vector<int> memo1;
    vector<int> memo2;
    vector<int> cost;
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        memo1 = vector<int>(nums.size(), -1);
        memo2 = vector<int>(nums.size(), -1);
        cost = nums;
        return max(dp1(nums.size()-1), dp2(nums.size()-2));
    }
    int dp1(int i) {
        if (i < 1) return 0;
        if(i==2) {
            return max(cost[1], cost[2]);
        }
        if(i==1) {
            return cost[1];
        }
        if(memo1[i]!=-1) {
            return memo1[i];
        }
        memo1[i] = max(dp1(i-2)+cost[i], dp1(i-1));
        return memo1[i];
    }
    int dp2(int i) {
        if (i < 0) return 0;
        if(i==0) {
            return cost[0];
        }
        if(i==1) {
            return max(cost[1], cost[0]);
        }
        if(memo2[i]!=-1) {
            return memo2[i];
        }
        memo2[i] = max(dp2(i-2)+cost[i], dp2(i-1));
        return memo2[i];
    }
};