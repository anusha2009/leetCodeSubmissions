class UnionFind {
public:
    vector<int> root;
    vector<int> rank;
    UnionFind(int size) : root(size), rank(size) {
        for(int i = 0; i<size; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }
    int find(int x) {
        if(root[x] == x) {
            return x;
        }
        return root[x]=find(root[x]);
    }
    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX != rootY) {
            if(rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if(rank[rootY] > rank[rootX]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf(26);
        for(auto equation : equations) {
            if(equation[1] == '=') {
                uf.unionSet(equation[0] - 'a', equation[3] - 'a');
            }
        }
        for(auto equation : equations) {
            if(equation[1] == '!' && uf.find(equation[0]-'a') == uf.find(equation[3]-'a')) {
                return false;
            }
        }
        return true;
    }
};