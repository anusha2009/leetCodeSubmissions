class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int n=board.size();
        int m=board[0].size();
        for(int a=0;a<n;a++){
            for(int b=0;b<m;b++){
                int count=0;
                for(int c=a-1;c<=a+1;++c){
                    for(int d=b-1;d<=b+1;++d){
                        if(c==a && d==b) continue;
                        if(c>=0 && c<n && d>=0 && d<m && (board[c][d]==1 || board[c][d]==3)){
                            count++;
                        }
                    }
                }

                if(board[a][b]==1 && (count<2 || count>3)){
                    board[a][b]=3;
                }
                if(board[a][b]==0 && count==3){
                    board[a][b]=2;
                }
            }
        }
        for(int a=0;a<n;++a){
            for(int b=0;b<m;++b){
                if(board[a][b]==3){
                    board[a][b]=0;
                }
                if(board[a][b]==2){
                    board[a][b]=1;
                }
            }
        }
    }
};