class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i = 0; i<=n; i++) {
            int count = 0;
            int j = i;
            while(j!=0) {
                count++;
                j &= (j-1);
            }
            res.push_back(count);
        }
        return res;
    }
};