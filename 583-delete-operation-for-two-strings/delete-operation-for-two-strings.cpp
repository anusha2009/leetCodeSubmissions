class Solution {
public:
    vector<vector<int>> memo;
    int m;
    int n;
    string s1;
    string s2;
    int minDistance(string word1, string word2) {
        this->m = word1.size();
        this->n = word2.size();
        this->s1 = word1;
        this->s2 = word2;
        memo = vector(m, vector<int>(n, -1));
        int lcs = dp(0, 0);
        int res = (m + n) - (2*lcs);
        return res;
    }
    int dp(int i, int j) {
        if(i>=m || j>=n) {
            return 0;
        }
        if(memo[i][j]!=-1) {
            return memo[i][j];
        }
        int ans = 0;
        if(s1[i]==s2[j]) {
            ans = 1 + dp(i+1, j+1);
        } else {
            ans = max(dp(i+1, j), dp(i, j+1));
        }
        memo[i][j] = ans;
        return ans;
    }
};