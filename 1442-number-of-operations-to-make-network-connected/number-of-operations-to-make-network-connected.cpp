class UnionFind {
    private:
        int count;
        vector<int> root;
        vector<int> rank;
    public: 
        UnionFind(int size): count(size), root(size), rank(size) {
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
        void unionSet(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if(rootX!=rootY) {
                if(rank[rootX]>rank[rootY]) {
                    root[rootY] = rootX;
                } else if(rank[rootY]>rank[rootX]) {
                    root[rootX] = rootY;
                } else {
                    root[rootY] = rootX;
                    rank[rootX]++;
                }
                count--;
            }
        }
        int getCount() {
            return count;
        }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) {
            return -1;
        }
        UnionFind uf(n);
        for(auto& c : connections) {
            uf.unionSet(c[0], c[1]);
        }
        return uf.getCount()-1;

    }
};