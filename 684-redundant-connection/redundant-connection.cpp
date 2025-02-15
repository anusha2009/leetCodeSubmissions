class UnionFind {
    private:
        vector<int> root;
        vector<int> rank;
    public:
        UnionFind(int size) : root(size), rank(size) {
            for(int i = 0; i<size; i++) {
                root[i] = i;
                rank[i] = 1;
            }
        }
        int find(int x) {
            if(x == root[x]) {
                return x;
            }
            return root[x] = find(root[x]);
        }
        bool unionSet(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if(rootX != rootY) {
                if(rank[rootX]>rank[rootY]) {
                    root[rootY] = rootX;
                } else if(rank[rootY]>rank[rootX]) {
                    root[rootX] = rootY;
                } else {
                    root[rootY] = rootX;
                    rank[rootX]++;
                }
            } else {
                return false;
            }
            return true;
        }

};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> result;
        UnionFind uf(n+1);
        for(auto& edge : edges) {
            if(!uf.unionSet(edge[0], edge[1])){
                return {edge[0], edge[1]};
            }
        }
        return {-1, -1};
    }
};