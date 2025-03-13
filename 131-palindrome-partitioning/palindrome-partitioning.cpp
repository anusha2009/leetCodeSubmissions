class Solution {
public:
    vector<vector<string>> result;
    vector<string> currList;
    string s;
    
    vector<vector<string>> partition(string s) {
        this->s = s;
        backtrack(0);
        return result;
    }
    
    void backtrack(int start) {
        if (start == s.size()) {
            result.push_back(currList);
            return;
        }
        
        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(start, end)) {
                currList.push_back(s.substr(start, end - start + 1));
                backtrack(end + 1);
                currList.pop_back(); // Backtrack
            }
        }
    }

    bool isPalindrome(int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
