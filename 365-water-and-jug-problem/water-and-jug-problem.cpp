class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(target>x+y){
            return false;
        }
        if(target==0){
            return true;
        }
        if(x==0){
            return y==target;
        }
        if(y==0){
            return x==target;
        }
        queue<pair<int,int>>q;
        set<pair<int,int>>visited;
        q.push({0,0});
        visited.insert({0,0}); 
        while(!q.empty()){
            auto [dx,dy]=q.front();
            q.pop();
            if(dx+dy==target){
                return true;
            }
            vector<pair<int, int>> dirs = {
                {x, dy},
                {dx, y},
                {0, dy},
                {dx, 0}, 
                {dx - min(dx, y - dy), dy + min(dx, y - dy)},
                {dx + min(dy, x - dx), dy - min(dy, x - dx)} 
            };
            for(auto [nx,ny]:dirs){
                if(visited.count({nx,ny})==0){
                    visited.insert({nx,ny});
                    q.push({nx,ny});
                }
            }
        }
        return false;
    }
};