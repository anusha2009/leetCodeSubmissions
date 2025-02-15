class UnionFind {
    private: 
        int count;
        vector<int> root;
        vector<int> rank;

    public:
        UnionFind(int size): root(size), rank(size), count(size) {
            for(int i =0;i<size;i++) {
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
            if(rootX != rootY) {
                if(rank[rootX]>rank[rootY]) {
                    root[rootY] = rootX;
                } else if(rank[rootX]<rank[rootY]) {
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
    int countComponents(int n, vector<vector<int>>& edges) {
        if(n==0) {
            return 0;
        }
        UnionFind uf(n);
        for(auto& edge: edges) {
            uf.unionSet(edge[0], edge[1]);
        }
        return uf.getCount();
        /*unordered_map<int, vector<int>> graph;
        vector<bool> seen(n, false);
        for(auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int count = 0;
        for(int i=0;i<n;i++) {
            if(!seen[i]) {
                count++;
                dfs(i, graph, seen);
            }
        }
        return count;*/
        
    }
    void dfs(int source, unordered_map<int, vector<int>>& graph, vector<bool>& seen) {
            seen[source] = true;
            for(auto& neighbour : graph[source]) {
                if(!seen[neighbour]) {
                    dfs(neighbour, graph, seen);
                }
            }
    }
};