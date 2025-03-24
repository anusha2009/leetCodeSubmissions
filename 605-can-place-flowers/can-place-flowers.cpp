class Solution {
public:
    vector<int> memo;
    vector<int> flowerbed;
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        this->flowerbed = flowerbed;
        memo = vector<int>(flowerbed.size(), -1);
        return dp(0, n) == 1;
    }
    int dp(int i, int n) {
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
        if(flowerbed[i] == 0 && (i==0 || flowerbed[i-1] == 0 ) && (i==flowerbed.size()-1 || flowerbed[i+1] == 0)) {
            flowerbed[i] = 1;
            ans = dp(i+1, n-1);
        } else {
            ans = dp(i+1, n);
        }
        memo[i] = ans;
        return ans;
    }
};