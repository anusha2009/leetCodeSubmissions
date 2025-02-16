class UnionFind {
    private:
        vector<int> root;
        vector<int> rank;
    public: 
        UnionFind(int size): root(size), rank(size) {
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
                return true;
            } else {
                return false;
            }

        }
};
class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) {
            return -1;
        }
        UnionFind uf(n+1);
        int totalCost = 0;
        int merges = 0;
        sort(connections.begin(), connections.end(), [](auto& a, auto& b) {return a[2]<b[2];});
        for(auto& c : connections) {
            int x = c[0];
            int y = c[1];
            int cost = c[2];
            if(uf.unionSet(x, y)) {
                totalCost += cost;
                merges++;
                if(merges == n-1) {
                    return totalCost;
                }
            }
        }
        return -1;
    }
};