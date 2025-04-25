class UnionFind {
public:
    vector<int> root;
    vector<int> rank;
    int count;
    UnionFind(int size) : root(size), rank(size), count(size) {
        for(int i = 0; i<size; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }
    int find(int x) {
        if(root[x] == x) {
            return x;
        }
        return root[x] = find(root[x]);
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
            count--;
        }
    }
    int getCount() {
        return count;
    }
};
class Solution {
public:
    bool isSimilar(string s1, string s2) {
        int diff = 0;
        for(int i = 0; i<s1.size(); i++) {
            if(s1[i] != s2[i]) {
                diff++;
            }
        }
        return diff == 0 || diff == 2;
    }
    int numSimilarGroups(vector<string>& strs) {
        UnionFind uf(strs.size());
        for(int i = 0; i<strs.size(); i++) {
            for(int j = i+1; j<strs.size(); j++) {
                if(isSimilar(strs[i], strs[j])) {
                    uf.unionSet(i, j);
                }
            }
        }
        return uf.getCount();
    }
};