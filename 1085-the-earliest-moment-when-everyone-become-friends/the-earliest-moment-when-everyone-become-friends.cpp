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
    bool unionSet(int time, int x, int y) {
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
        } 
        return false;       

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
    int earliestAcq(vector<vector<int>>& logs, int n) {
        if(logs.size() == 0) {
            return -1;
        }
        sort(logs.begin(), logs.end());
        UnionFind uf(n);
        int time;
        for(int i=0;i<logs.size();i++) {
            bool valid = uf.unionSet(logs[i][0], logs[i][1], logs[i][2]);
            if(valid) {
                time = logs[i][0];
            }
            if(uf.getCount()==1) {
                return time;
            }
        }
        return uf.getCount()==1? time:-1;
    }
};