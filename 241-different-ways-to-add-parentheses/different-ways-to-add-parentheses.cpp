class Solution {
public:
    vector<vector<vector<int>>> memo;
    string expression;
    int len;
    vector<int> diffWaysToCompute(string expression) {
        this->expression = expression;
        len = expression.size();
        memo = vector<vector<vector<int>>>(len, vector<vector<int>>(len));
        return dp(0, len-1);
    }
    vector<int> dp(int i, int j) {
        if (!memo[i][j].empty()) {
            return memo[i][j];
        }
        vector<int> results;
        // Base case: single digit
        if (i == j) {
            results.push_back(expression[i] - '0');
            return results;
        }
        // Base case: two-digit number
        if (j - i == 1 && isdigit(expression[i])) {
            int tens = expression[i] - '0';
            int ones = expression[j] - '0';
            results.push_back(10 * tens + ones);
            return results;
        }
        // Iterate over all operators in the expression
        for (int k = i; k <= j; k++) {
            if (isOperator(expression[k])) {
                vector<int> leftResults = dp(i, k - 1);
                vector<int> rightResults = dp(k + 1, j);

                // Combine results from left and right subexpressions
                for (int left : leftResults) {
                    for (int right : rightResults) {
                        if (expression[k] == '+') {
                            results.push_back(left + right);
                        } else if (expression[k] == '-') {
                            results.push_back(left - right);
                        } else if (expression[k] == '*') {
                            results.push_back(left * right);
                        }
                    }
                }
            }
        }

        return memo[i][j] = results;
    }
    
    // Helper function to check if a character is an operator
    bool isOperator(char ch) {
        return ch == '+' || ch == '-' || ch == '*';
    }
};