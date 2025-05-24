class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int u = 0;
        int d = n-1;
        int l = 0;
        int r = n-1;
        int val = 1;
        while(l <= r && u <= d) {
            if(l<=r && u<=d) {
                for(int i = l; i<=r; i++) {
                    result[u][i] = val;
                    val++;
                }
                u++;
            }
            if(l<=r && u<=d) {
                for(int i=u; i<=d; i++) {
                    result[i][r] = val;
                    val++;
                }
                r--;
            }
            if(l<=r && u<=d) {
                for(int i=r; i>=l; i--) {
                    result[d][i] = val;
                    val++;
                }
                d--;
            }
            if(l<=r && u<=d) {
                for(int i=d; i>=u; i--) {
                    result[i][l] = val;
                    val++;
                }
                l++;
            }
        }
        return result;
    }
};