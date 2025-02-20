class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> res;
        for(int num : nums) {
            if(num==0) {
                res.push_back(num);
            }
        }
        for(int num : nums) {
            if(num==1) {
                res.push_back(num);
            }
        }
        for(int num : nums) {
            if(num==2) {
                res.push_back(num);
            }
        }
        nums = res;
    }
};