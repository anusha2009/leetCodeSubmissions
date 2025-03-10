class Solution {
public:
    vector<int> memo;
    vector<int> nums;
    int n;
    int jump(vector<int>& nums) {
        memo = vector<int>(nums.size(), INT_MAX); // Use nums.size(), no need for +1
        n = nums.size();
        this->nums = nums;
        return dp(0);
    }
    int dp(int i) {
        if (i >= n - 1) {  // Base case: If we reach or exceed last index, return true
            return 0;
        }
        if (memo[i] != INT_MAX) { // If we have already computed this state, return it
            return memo[i];
        }
        for (int j = 1; j <= nums[i]; j++) {  // Iterate through possible jumps
            if (dp(i + j)!=INT_MAX) {  // If any jump reaches the end, return true
                memo[i] = min(memo[i], 1 + dp(i+j));
            }
        }
        return memo[i];  // If no jump works, return false
    }
};
