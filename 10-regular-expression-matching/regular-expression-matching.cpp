class Solution {
public:
    vector<vector<int>> memo;
    int m, n;
    string s, p;

    bool isMatch(string s, string p) {
        this->m = s.size();
        this->n = p.size();
        this->s = s;
        this->p = p;
        memo = vector<vector<int>>(m + 1, vector<int>(n + 1, -1));
        return dp(0, 0);
    }

    bool dp(int i, int j) {
        // Base case: If both string and pattern are fully matched
        if (i == m && j == n) return true;

        // If pattern is exhausted but string is not
        if (j == n) return false;

        // Check if result is already computed
        if (memo[i][j] != -1) return memo[i][j];

        bool ans = false;

        // Check if first character of s and p match
        bool firstMatch = (i < m && (s[i] == p[j] || p[j] == '.'));

        // Handle '*' (zero or more occurrences of preceding character)
        if (j + 1 < n && p[j + 1] == '*') {
            ans = dp(i, j + 2) || (firstMatch && dp(i + 1, j));
        } 
        // Handle normal character match or '.'
        else {
            ans = firstMatch && dp(i + 1, j + 1);
        }

        return memo[i][j] = ans;
    }
};
