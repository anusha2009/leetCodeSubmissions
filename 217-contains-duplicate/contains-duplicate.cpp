class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       map <int,int> m;
        
        for(int i=0;i<nums.size();i++)
            
        {
            if(m[nums[i]]==1)
            
                return true;               //the moment it finds duplicate, returns true.
            
            m[nums[i]]=1;
        }
        return false;
    
    }
};