class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int res = nums[0];
    int maxEnding = nums[0];

    for (int i = 1; i < nums.size(); i++) {
      
        // Find the maximum sum ending at index i by either extending 
        // the maximum sum subarray ending at index i - 1 or by
        // starting a new subarray from index i
        maxEnding = max(maxEnding + nums[i], nums[i]);
      
        // Update res if maximum subarray sum ending at index i > res
        res = max(res, maxEnding);
    }
    return res;
    }
};