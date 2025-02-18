class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        vector<vector<int>> adjList(N+1);
        vector<int> inDegree(N+1, 0);
        vector<int> q;
        int semester = 0;
        int courses = 0;
        for(auto& relation : relations) {
            int source = relation[0];
            int dest = relation[1];
            adjList[source].push_back(dest);
            inDegree[dest]++;
        }
        for(int i = 0;i<inDegree.size(); i++) {
            if(inDegree[i]==0) {
                q.push_back(i);
            }
        }
        while(!q.empty()) {
            semester++;
            vector<int> nextQueue;
            for (auto& node : q) {
                courses++;
                for (auto& endNode : adjList[node]) {
                    inDegree[endNode]--;
                    // if all prerequisite courses learned
                    if (inDegree[endNode] == 0) {
                        nextQueue.push_back(endNode);
                    }
                }
            }
            q = nextQueue;
        }
        return courses == N+1? semester:-1;

    }
};