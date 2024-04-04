class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //can be done by using a pointer
        if(nums.size()==1 || nums.size()==0)
            return nums.size();
        int duplicate_verify=0;
        for(int i=0;i<nums.size()-1;i++){
            
            if(nums[i]!=nums[i+1]){
                nums[duplicate_verify++] = nums[i];
            }
        }

        nums[duplicate_verify++]=nums[nums.size()-1];
        return duplicate_verify;
        
    }
};