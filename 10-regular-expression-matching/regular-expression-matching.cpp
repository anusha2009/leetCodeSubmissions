enum Result { TRUE, FALSE, NONE };

class Solution {
public:
    vector<vector<Result>> memo;

    bool isMatch(string text, string pattern) {
        memo = vector<vector<Result>>(text.size() + 1, vector<Result>(pattern.size() + 1, NONE));
        return dp(0, 0, text, pattern);
    }

    bool dp(int i, int j, string &text, string &pattern) {
        if (memo[i][j] != NONE) {
            return memo[i][j] == TRUE;
        }
        bool ans;
        if (j == pattern.size()) {
            ans = (i == text.size());
        } else {
            bool first_match = (i < text.size() && (pattern[j] == text[i] || pattern[j] == '.'));

            if (j + 1 < pattern.size() && pattern[j + 1] == '*') {
                ans = (dp(i, j + 2, text, pattern) || (first_match && dp(i + 1, j, text, pattern)));
            } else {
                ans = first_match && dp(i + 1, j + 1, text, pattern);
            }
        }
        memo[i][j] = ans ? TRUE : FALSE;
        return ans;
    }
};
