class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            //Since it is already -ve, that means it has occurred earlier.
            //Add this to the output list.
            if(nums[abs(nums[i])-1]<0){
                ans.push_back(abs(nums[i]));
            }

            //Mark the index -ve.
            else{
                nums[abs(nums[i])-1] *= -1;
            }
        }
        return ans;
    }
};