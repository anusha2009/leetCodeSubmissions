class UnionFind {
public:
    UnionFind(int size): root(size), rank(size), count(size) {
        for(int i=0;i<size;i++) {
            root[i]=i;
            rank[i]=1;
        }
    }
    int find(int x) {
        if(x==root[x]) {
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
            } else if(rank[rootY]>rank[rootX]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
            count--;
        }

    }
    int getCount() {
        return count;
    }
private:
    vector<int> root;
    vector<int> rank;
    int count;
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        if(n==0 || (edges.size()==0)) {
            return 0;
        }
        UnionFind uf(n);
        for(int i=0;i<edges.size();i++) {
            uf.unionSet(edges[i][0], edges[i][1]);
        }
        return uf.getCount();
        
    }
};