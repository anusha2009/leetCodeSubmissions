class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        if(n == 1) {
            return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        }
        vector<int> result;
        for(int i = 1; i<10; i++) {
            backtrack(i, result, n-1, k);
        }
        return result;
    }
    void backtrack(int curr, vector<int>& result, int n, int k) {
        if(n==0) {
            result.push_back(curr);
            return;
        }
        vector<int> next;
        int tail = curr % 10;
        next.push_back(tail + k);
        if(k!=0) {
            next.push_back(tail - k);
        }
        for(int num : next) {
            if(num >= 0 && num < 10) {
                int newNum = curr * 10 + num;
                backtrack(newNum, result, n-1, k);
            }
        }

    }
};