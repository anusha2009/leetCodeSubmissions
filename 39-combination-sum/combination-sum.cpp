class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> ans;
        backtrack(curr, ans, candidates, target, 0);
        return ans;
        
    }
    void backtrack(vector<int>& curr, vector<vector<int>>& ans, vector<int>& candidates, int target, int index) {
        if(accumulate(curr.begin(), curr.end(), 0) == target) {
            ans.push_back(curr);
            return;
        }
        if(accumulate(curr.begin(), curr.end(), 0) > target) {
            return;
        }
        while(index<candidates.size()) {
            curr.push_back(candidates[index]);
            backtrack(curr, ans, candidates, target, index);
            curr.pop_back();
            index++;
        }
    }
};