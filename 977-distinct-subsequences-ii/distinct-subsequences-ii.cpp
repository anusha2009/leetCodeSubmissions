class Solution {
public:
    vector<int> memo;
    string s;
    const int MOD = 1e9 + 7;

    int distinctSubseq(int i, unordered_map<char, int>& lastSeen) {
        if (i < 0) return 1;  // Base case: empty subsequence
        
        if (memo[i] != -1) return memo[i];  // Memoization check

        // Compute the number of subsequences for s[0...i]
        long long result = (2 * distinctSubseq(i - 1, lastSeen)) % MOD;

        char currChar = s[i];
        if (lastSeen.count(currChar)) {
            // Remove duplicate subsequences created by previous occurrences of currChar
            result = (result - distinctSubseq(lastSeen[currChar] - 1, lastSeen) + MOD) % MOD;
        }

        // Store the last occurrence of this character
        lastSeen[currChar] = i;

        return memo[i] = result;
    }

    int distinctSubseqII(string s) {
        this->s = s;
        int n = s.size();
        memo = vector<int>(n, -1);
        unordered_map<char, int> lastSeen;

        return (distinctSubseq(n - 1, lastSeen) - 1 + MOD) % MOD;  // Exclude the empty subsequence
    }
};