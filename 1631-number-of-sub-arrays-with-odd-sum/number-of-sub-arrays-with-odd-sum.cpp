class Solution {
public:
    vector<vector<int>> memo;
    int size;
    vector<int> arr;
    const int MOD = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        memo = vector(arr.size(), vector<int>(2, -1));
        this->size = arr.size();
        this->arr = arr;
        int count = 0;
        for(int i = 0; i<arr.size(); i++) {
            count = (count + dp(i, 0)) % MOD;
        }
        return count;
    }
    int dp(int i, int sum) {
        if(i>=size) {
            return 0;
        }
        if(memo[i][sum]!=-1) {
            return memo[i][sum];
        }
        int ans = 0;
        if((sum + arr[i])%2 != 0) {
            ans = (1 + dp(i+1, 1)) % MOD;
        } else {
            ans = dp(i+1, 0);
        }
        memo[i][sum] = ans;
        return ans;

    }
};