#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1)
            return 0;
        // Initialize memoization vector with 0's (size = amount).
        vector<int> count(amount, 0);
        return coinChangeHelper(coins, amount, count);
    }
    
private:
    int coinChangeHelper(vector<int>& coins, int rem, vector<int>& count) {
        if (rem < 0)
            return -1;
        if (rem == 0)
            return 0;
        // If we've already computed the result for this remainder, return it.
        if (count[rem - 1] != 0)
            return count[rem - 1];
        
        int minCoins = numeric_limits<int>::max();
        for (int coin : coins) {
            int res = coinChangeHelper(coins, rem - coin, count);
            if (res >= 0 && res < minCoins)
                minCoins = 1 + res;
        }
        count[rem - 1] = (minCoins == numeric_limits<int>::max() ? -1 : minCoins);
        return count[rem - 1];
    }
};
