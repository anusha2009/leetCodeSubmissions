class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        int mod = 1e9 + 7;
        long dp_1 = 0, dp_0 = 0;
        bool hasZero = false;
        
        for (char c : binary) {
            if (c == '1') {
                dp_1 = (dp_1 + dp_0 + 1) % mod;  // Every '1' forms new sequences
            } else {
                dp_0 = (dp_1 + dp_0) % mod;  // Every '0' extends previous sequences
                hasZero = true;
            }
        }
        
        return (dp_1 + dp_0 + hasZero) % mod;
    }
};
