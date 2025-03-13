class Solution {
public:
    vector<int> memo;
    vector<int> perfectSquares;
    int numSquares(int n) {
        memo = vector<int>(n+1, -1);
        for(int i = 1; i<=n; i++) {
            int squareRoot = sqrt(i);
            if((squareRoot * squareRoot) == i) {
                perfectSquares.push_back(i);
            }
        }
        return dp(n);
    }
    int dp(int n) {
        if(n<0) {
            return -1;
        }
        if(n==0) {
            return 0;
        }
        if(memo[n]!=-1) {
            return memo[n];
        }
        int ans = INT_MAX;
        for(int squares : perfectSquares) {
            int res = dp(n-squares);
            if(res>=0 && res<ans) {
                ans = res + 1;
            }
        }
        memo[n] = ans == INT_MAX? -1 : ans;
        return ans;
    }
};