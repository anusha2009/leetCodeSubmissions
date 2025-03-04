class Solution {
public:
    vector<vector<int>> memo;
    int len;
    string s3;
    string s1;
    string s2;

    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        len = s3.size();
        
        // Length check: If s1 + s2 != s3, return false immediately
        if (m + n != len) return false;

        this->s3 = s3;
        this->s1 = s1;
        this->s2 = s2;
        
        memo = vector<vector<int>>(m + 1, vector<int>(n + 1, -1));
        return dp(0, 0);
    }

    int dp(int i, int j) {
        if (i == s1.size() && j == s2.size()) {
            return 1;  // Successfully matched all characters
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        bool ans = false;
        
        if (i < s1.size() && s1[i] == s3[i + j]) {
            ans |= dp(i + 1, j);
        }
        
        if (j < s2.size() && s2[j] == s3[i + j]) {
            ans |= dp(i, j + 1);
        }

        memo[i][j] = ans;
        return ans;
    }
};
