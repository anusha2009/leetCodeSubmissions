class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int maxSum = INT_MIN;
        unordered_map<int, int> map;
        for(int i=0;i<nums.size();i++) {
            int currSum = 0;
            int num = nums[i];
            while(num>0) {
                currSum += num%10;
                num = num/10;
            }
            if(map.find(currSum)!=map.end()) {
                maxSum = max(maxSum, map[currSum]+nums[i]);
            }
            map[currSum] = max(nums[i], map[currSum]);
            
        }
        return maxSum == INT_MIN? -1:maxSum;

    }
};