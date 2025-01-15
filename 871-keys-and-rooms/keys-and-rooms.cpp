class Solution {
public:
    vector<vector<int>> rooms;
    unordered_set<int> seen;
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        this->rooms = rooms;
        seen.insert(0);
        dfs(0);
        return seen.size() == rooms.size();
    }
    
    void dfs(int node) {
        for (int neighbor: rooms[node]) {
            if (seen.find(neighbor) == seen.end()) {
                seen.insert(neighbor);
                dfs(neighbor);
            }
        }
    }
    
};