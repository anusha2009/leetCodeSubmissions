class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int minsofar=INT_MAX;  int ans=0;
        for(int i=0;i<nums.size();i++){
            minsofar=min(minsofar,nums[i]);
            ans=max(ans,nums[i]-minsofar);  }
     return ans;
    }
};

