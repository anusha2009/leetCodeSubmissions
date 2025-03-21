class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        for(int num : nums) {
            if(num<pivot) {
                ans.push_back(num);
            }
        }
        for(int num : nums) {
            if(num==pivot) {
                ans.push_back(num);
            }
        }
        for(int num : nums) {
            if(num>pivot) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};