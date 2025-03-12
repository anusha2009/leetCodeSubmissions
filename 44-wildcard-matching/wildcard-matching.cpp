class Solution {
public:
    vector<vector<int>> memo;
    int m;
    int n;
    string s;
    string p;
    bool isMatch(string s, string p) {
        this->m = s.size();
        this->n = p.size();
        this->s = s;
        this->p = p;
        memo = vector(m+1, vector<int>(n+1, -1));
        return dp(0, 0);
    }
    bool dp(int i, int j) {
        if(i==m && j==n) {
            return true;
        }
        // If pattern is exhausted but string is not, return false
        if (j == n) return false;

        // If string is exhausted, check if remaining pattern can be matched by '*'
        if (i == m) {
            while (j < n) {
                if (p[j] != '*') return false;
                j++;
            }
            return true;
        }
        if(memo[i][j]!=-1) {
            return memo[i][j];
        }
        bool ans = false;
        if(p[j] == '?' || s[i]==p[j]) {
            ans = dp(i+1, j+1);
        } else if (p[j] == '*') {
            ans = dp(i+1, j) || dp(i, j+1);
        } 
        memo[i][j] = ans;
        return ans;

    }
};