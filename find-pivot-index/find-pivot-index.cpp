class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalCount = 0;
        int currCount = 0;
        for(int num:nums) {
            totalCount += num;
        }
        for(int i=0;i<nums.size();i++) {
            currCount += nums[i];
            if(currCount - nums[i] == totalCount - currCount) {
                return i;
            }
        }
        return -1;
    }
};