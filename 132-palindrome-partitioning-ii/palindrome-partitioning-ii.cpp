class Solution {
public:
    string s;
    int len;
    vector<vector<int>> memo;
    int minCut(string s) {
        this->s = s;
        this->len = s.size();
        memo = vector(len, vector<int>(len, -1));
        return dp(0, len-1);
    }
    int dp(int i, int j) {
        if(i==j) {
            return 0;
        }
        if(isPalindrome(i, j)) {
            return 0;
        }
        if(memo[i][j]!=-1) {
            return memo[i][j];
        }
        int ans = INT_MAX;
        for(int k = i; k<j; k++) {
            if(isPalindrome(i, k)) {
                int res = dp(k+1, j) + 1;
                ans = min(ans, res);
            }
        }
        memo[i][j] = ans;
        return ans;
    }
    bool isPalindrome(int i, int j) {
        while(i<j) {
            if(s[i]!=s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};