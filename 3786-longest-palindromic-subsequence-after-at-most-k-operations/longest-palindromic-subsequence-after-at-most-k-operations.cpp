class Solution {
public:
    vector<vector<vector<int>>> memo;
    int longestPalindromicSubsequence(string s, int k) {
        memo.resize(s.size()+1, vector<vector<int>>(s.size()+1, vector<int>(k+1, -1)));
        return dp(s, 0, s.size() - 1, k);
    }
    int dp(const string& s, int l, int r, int k) {
        if (l > r) return 0; // Return 0 since it's empty string
        if (l == r) return 1; // Return 1 since it has 1 character
        if (memo[l][r][k] != -1) return memo[l][r][k];
        int res = 0;
        int diff = min(abs(s[l]-s[r]), 26-abs(s[l]-s[r]));
        if(diff<=k) {
            res = max(res, dp(s, l+1, r-1, k-diff) + 2);
        }
        return memo[l][r][k] = max({res, dp(s, l+1, r, k), dp(s, l, r-1, k)});
    }
};