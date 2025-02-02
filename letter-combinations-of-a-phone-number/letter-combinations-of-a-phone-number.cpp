class Solution {
public:
    unordered_map<char, string> letters = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string curr;
        if(!digits.size()) {
            return ans;
        }
        backtrack(curr, ans, digits, 0);
        return ans;
        
    }
    void backtrack(string curr, vector<string>& ans, string digits, int index) {
        if(curr.size() == digits.size()) {
            ans.push_back(curr);
            return;
        }
        for ( char letter : letters[digits[index]]) {
            curr.push_back(letter);
            backtrack(curr, ans, digits, index+1);
            curr.pop_back();
        }
        

    }
};