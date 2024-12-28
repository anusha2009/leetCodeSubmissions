class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int sum = 0;
        while(size!=0) {
            sum = sum + size;
            size--;
            
        }
        int currSum = 0;
        for (int i=0; i<nums.size(); i++) {
            currSum = currSum + nums[i];
        }
        int result = sum - currSum;
        return result;
        
    }
};