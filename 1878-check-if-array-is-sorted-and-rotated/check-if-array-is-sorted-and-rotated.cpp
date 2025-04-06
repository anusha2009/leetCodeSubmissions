class Solution {
public:
    bool check(vector<int>& nums) {
        int i = 0;
        int j = 0;
        while(i<nums.size()) {
            if(i!=0 && nums[i]<nums[i-1]) {
                j = i;
                break;
            }
            i++;
        }
        i = 0;
        while(i<j) {
            nums.push_back(nums[i]);
            i++;
        }
        for(int i = j; i<nums.size(); i++) {
            if(i!=j && nums[i]<nums[i-1]) {
                return false;
            }
        }
        return true;
    }
};