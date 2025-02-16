class Edge {
public:
    int point1;
    int point2;
    int cost;
    Edge(int point1, int point2, int cost)
        : point1(point1), point2(point2), cost(cost) {}
};
// Overload the < operator.
bool operator<(const Edge& edge1, const Edge& edge2) {
    return edge1.cost > edge2.cost;
}

class UnionFind {
public:
    UnionFind(int sz) : root(sz), rank(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

private:
    vector<int> root;
    vector<int> rank;
};
class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        if(n==0) {
            return 0;
        }
        priority_queue<Edge> pq;
        UnionFind uf(n + n);
        for(int i = 0; i<wells.size(); i++) {
            Edge edge(0, i+1, wells[i]);
            pq.push(edge);
        }
        for(int i = 0; i<pipes.size(); i++) {
            Edge edge(pipes[i][0], pipes[i][1], pipes[i][2]);
            pq.push(edge);
        }
        int totalCost = 0;
        int count = 2*n - 1;
        while(!pq.empty() && count>0) {
            Edge edge = pq.top();
            pq.pop();
            if (!uf.connected(edge.point1, edge.point2)) {
                uf.unionSet(edge.point1, edge.point2);
                totalCost += edge.cost;
                count--;
            }
        }
        return totalCost;
    }
};