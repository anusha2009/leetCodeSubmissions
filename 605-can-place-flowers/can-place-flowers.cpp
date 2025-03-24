class Solution {
public:
    vector<int> memo;
    vector<int> flowerbed;
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        this->flowerbed = flowerbed;
        memo = vector<int>(flowerbed.size(), -1);
        return dp(0, n, 0) == 1;
    }
    int dp(int i, int n, int flag) {
        if(n==0) {
            return true;
        }
        if(i>=flowerbed.size()) {
            return false;
        }
        if(memo[i]!=-1) {
            return memo[i];
        }
        int ans;
        if(flowerbed[i] == 0 && (i==0 || flag == 0 ) && (i==flowerbed.size()-1 || flowerbed[i+1] == 0)) {
            ans = dp(i+1, n-1, 1);
        } else if(flowerbed[i] == 1) {
            ans = dp(i+1, n, 1);
        } else {
            ans = dp(i+1, n, 0);
        }
        memo[i] = ans;
        return ans;
    }
};