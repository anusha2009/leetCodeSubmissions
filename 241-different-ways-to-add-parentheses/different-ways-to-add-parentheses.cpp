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
        // Base case: if it's a single digit, return its value as an integer
        if (isDigit(i, j)) {
            results.push_back(stoi(expression.substr(i, j - i + 1)));
            return memo[i][j] = results;
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
    // Helper function to check if a substring is just a number
    bool isDigit(int i, int j) {
        for (int k = i; k <= j; k++) {
            if (!isdigit(expression[k])) return false;
        }
        return true;
    }
    // Helper function to check if a character is an operator
    bool isOperator(char ch) {
        return ch == '+' || ch == '-' || ch == '*';
    }
};