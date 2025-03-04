class Solution {
public:
    vector<int> memo;
    vector<int> nums;
    int n;

    bool canJump(vector<int>& nums) {
        memo = vector<int>(nums.size(), -1); // Use nums.size(), no need for +1
        n = nums.size();
        this->nums = nums;
        return dp(0);
    }

    bool dp(int i) {
        if (i >= n - 1) {  // Base case: If we reach or exceed last index, return true
            return true;
        }
        if (memo[i] != -1) { // If we have already computed this state, return it
            return memo[i];
        }
        for (int j = 1; j <= nums[i]; j++) {  // Iterate through possible jumps
            if (dp(i + j)) {  // If any jump reaches the end, return true
                return memo[i] = true;
            }
        }
        return memo[i] = false;  // If no jump works, return false
    }
};
