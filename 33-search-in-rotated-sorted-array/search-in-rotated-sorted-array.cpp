class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n=nums.size();
        if(n==0)
            return -1;
        int i=0;

        int j=n-1;
        int m;
        while(i<=j)
        {
            m=(i+j)/2;
            if(nums[m]==target)
                return m;
            else if(nums[0]<=nums[m])
            {
                if(target>=nums[0]&&target<=nums[m])
                
                    j=m-1;
                else
                    i=m+1;
            }
            else
            {
                if(target>=nums[m]&&target<=nums[n-1])
                    i=m+1;
                else
                    j=m-1;
            }
        }
        return -1;
    
    }
};