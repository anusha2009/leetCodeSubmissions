class Solution {
public:
    string numStr;
    int memo[12][2][12]; // pos, tight, count_1s (at most 10 digits in int)

    int dp(int pos, bool tight, int count_1s) {
        if (pos == numStr.size()) {
            return count_1s; // base case: return total count of 1s
        }

        if (memo[pos][tight][count_1s] != -1) {
            return memo[pos][tight][count_1s];
        }

        int limit = tight ? (numStr[pos] - '0') : 9;
        int total = 0;

        for (int digit = 0; digit <= limit; ++digit) {
            bool newTight = tight && (digit == limit);
            int newCount = count_1s + (digit == 1 ? 1 : 0);
            total += dp(pos + 1, newTight, newCount);
        }

        return memo[pos][tight][count_1s] = total;
    }

    int countDigitOne(int n) {
        numStr = to_string(n);
        memset(memo, -1, sizeof(memo));
        return dp(0, true, 0); // start from position 0, tight=true, count=0
    }
};
