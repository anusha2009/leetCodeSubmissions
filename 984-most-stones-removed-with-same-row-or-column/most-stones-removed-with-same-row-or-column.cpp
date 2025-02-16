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
    int removeStones(vector<vector<int>>& stones) {
        // Step 1: find max row & col to define offset
        int maxRow=0, maxCol=0;
        for(auto &s : stones) {
            maxRow = max(maxRow, s[0]);
            maxCol = max(maxCol, s[1]);
        }
        int offset = maxRow + 1;  // columns start here
        UnionFind uf(maxRow + maxCol + 2);

        // Step 2: union each stone's row with col+offset
        unordered_set<int> usedNodes; // track row indices & (col+offset) used
        for(auto &s : stones) {
            int r = s[0], c = s[1] + offset;
            uf.unionSet(r, c);
            usedNodes.insert(r);
            usedNodes.insert(c);
        }

        // Step 3: count distinct roots among only the used nodes
        unordered_set<int> distinctRoots;
        for(int node : usedNodes) {
            distinctRoots.insert(uf.find(node));
        }

        int numComponents = distinctRoots.size();
        // Each connected component can keep exactly 1 stone, so remove rest
        return (int)stones.size() - numComponents;
    }
};