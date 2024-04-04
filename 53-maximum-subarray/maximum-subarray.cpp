class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsofar=INT_MIN;
        int maxend=0;
     
        for(int i=0;i<nums.size();i++)
        {
            maxend+=nums[i];
            maxsofar=max(maxsofar,maxend);
            if(maxend<0)
            
                maxend=0;
        }

        return maxsofar;
    }
};