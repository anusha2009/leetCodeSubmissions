class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr = {};
        backtrack(curr, 0, ans, nums);
        return ans;
    }
    
    void backtrack(vector<int>& curr, int i, vector<vector<int>>& ans, vector<int>& nums) {
        if (i > nums.size()) {
            return;
        }
        
        ans.push_back(curr);
        for (int j = i; j < nums.size(); j++) {
            curr.push_back(nums[j]);
            backtrack(curr, j + 1, ans, nums);
            curr.pop_back();
        }
    }
};