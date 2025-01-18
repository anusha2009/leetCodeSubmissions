class UnionFind {
public:
    UnionFind(int size): root(size), rank(size), count(size) {
        for(int i=0;i<size;i++) {
            root[i]=i;
            rank[i]=1;
        }
        size = size;
    }
    int find(int x) {
        if(x==root[x]) {
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
                rank[rootX] += 1;
            }
            count--;
            return true;  
        } else {
            return false;
        }
        

    }
    int getCount() {
        return count;
    }
private:
    vector<int> root;
    vector<int> rank;
    int count;
    int size;
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) {
            return false;
        }
        UnionFind uf(n);
        for(int i=0;i<edges.size();i++) {
            bool valid = uf.unionSet(edges[i][0], edges[i][1]);
            if(valid==false) {
                return valid;
            }
        }
        return uf.getCount()==1;
    }
};