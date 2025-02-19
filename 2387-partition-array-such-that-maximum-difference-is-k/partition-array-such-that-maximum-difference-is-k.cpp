class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 1;
        int x = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - x > k) {
                x = nums[i];
                ans++;
            }
        }
        
        return ans;
    }
};