class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        backtrack(curr, 0, 0, candidates, target);
        return ans;
    }
    void backtrack(vector<int>& curr, int index, int sum, vector<int>& candidates, int target) {
        if(sum == target) {
            ans.push_back(curr);
            return;
        } else if(sum>target) {
            return;
        }
        for(int i = index; i<candidates.size(); i++) {
            if(sum+candidates[i]<=target) {
                if (i > index && candidates[i] == candidates[i - 1]) continue;
                curr.push_back(candidates[i]);
                backtrack(curr, i+1, sum+candidates[i], candidates, target);
                curr.pop_back();
            }
        }
    }
};