class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> result;
        vector<long long> prefix;
        prefix.push_back(nums[0]);
        for(int i=1;i<nums.size();i++) {
            prefix.push_back(prefix.back() + nums[i]);
        }
        for(int i=0;i<nums.size();i++) {
            if(i<k || i>=nums.size()-k) {
                result.push_back(-1);
            } else {
                int res = (prefix[i+k]-prefix[i-k]+ nums[i-k])/((2*k)+1);
                result.push_back(res);
            }
        }
        return result;
    }
};