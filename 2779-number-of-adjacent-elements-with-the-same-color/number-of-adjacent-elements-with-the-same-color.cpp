class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> ans, nums(n, 0);
        int count = 0;
        for(auto q: queries){
            int i = q[0], val = q[1];
            if(nums[i] && i - 1 >= 0 && nums[i-1] == nums[i]) count--;  
            if(nums[i] && i + 1 < n && nums[i+1] == nums[i]) count--;
            nums[i] = val;
            if( i - 1 >= 0 && nums[i-1] == nums[i]) count++;
            if( i + 1 < n && nums[i+1] == nums[i]) count++;
            ans.push_back(count);
        }
        return ans;
    }
};