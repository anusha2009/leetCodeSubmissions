class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);

        for (auto& p : prerequisites) {
            int from = p[1];
            int to = p[0];
            graph[from].push_back(to);
            indegree[to]++;
        }

        queue<int> zeroDegree;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                zeroDegree.push(i);
            }
        }

        vector<int> result;
        while (!zeroDegree.empty()) {
            int course = zeroDegree.front();
            zeroDegree.pop();
            result.push_back(course);
            for (int child : graph[course]) {
                indegree[child]--;
                if (indegree[child] == 0) {
                    zeroDegree.push(child);
                }
            }
        }

        if(result.size() != numCourses){
            return {};
        }

        return result;
    }
};