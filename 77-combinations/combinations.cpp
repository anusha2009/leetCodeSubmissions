class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        vector<vector<int>> ans;
        backtrack(curr, ans, 1, n, k);
        return ans;
        
    }
    void backtrack(vector<int>& curr, vector<vector<int>>& ans, int first, int n, int k) {
        if(curr.size() == k) {
            ans.push_back(curr);
            return;
        }
        while(first<=n) {
            curr.push_back(first);
            backtrack(curr, ans, first+1, n, k);
            curr.pop_back();
            first++;
        }
    }
};