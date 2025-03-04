class Solution {
public:
    vector<vector<int>> memo;
    string s;
    string t;
    int m; 
    int n;
    int numDistinct(string s, string t) {
        this->s = s;
        this->t = t;
        this->m = s.size();
        this->n = t.size();
        memo = vector(m, vector<int>(n, -1));
        return dp(0, 0);
    }
    int dp(int i, int j) {
        // If we have matched all characters of t
        if (j == n) {
            return 1;
        }
        // If we reached the end of s and t is not completely matched
        if (i == m) {
            return 0;
        }
        if(memo[i][j]!=-1) {
            return memo[i][j];
        }
        int ans = 0;
        if(s[i]==t[j]) {
            ans = dp(i+1, j+1) + dp(i+1, j);
        } else {
            ans = dp(i+1, j);
        }
        memo[i][j] = ans;
        return memo[i][j];
    }
};