class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        map<int,int> mp1,mp2;
        int n = grid.size();

        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp1[grid[i][j]]++;
            }
        }
        
        
        
        int x = n/2;
        
        for(int i=0;i<=x;i++){
            mp2[grid[i][i]]++;
        }
        
         for(int i=n-1;i>=x;i--){
            mp2[grid[n-1-i][i]]++;
        }
        
        mp2[grid[x][x]]--;
        
        for(int i=x+1;i<n;i++){
            mp2[grid[i][x]]++;
        }
        
        mp1[0]-=mp2[0];
        mp1[1]-=mp2[1];
        mp1[2]-=mp2[2];
        
       
        // final answer calculation

        int ans = INT_MAX;
        
        long long sum1=0,sum2=0;
        for(auto val:mp1){
            sum1+=val.second;
        }
         for(auto val:mp2){
            sum2+=val.second;
        }
        
        //0;
        int n1 = sum1-mp1[0];
        int n2 = sum2-max(mp2[1],mp2[2]);
        ans = min(ans,n1+n2);
        
        //1;
        n1 = sum1-mp1[1];
        n2 = sum2-max(mp2[0],mp2[2]);
        ans = min(ans,n1+n2);
        
        //2
        n1 = sum1-mp1[2];
        n2 = sum2-max(mp2[0],mp2[1]);
        ans = min(ans,n1+n2);
        
        
        return ans;
        

    }
};

