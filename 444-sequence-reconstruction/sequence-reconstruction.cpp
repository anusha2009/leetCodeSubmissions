class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        
        // 1. Correct graph initialization: n+1 for 1-based node values
        vector<vector<int>> graph(n + 1);
        vector<int> indegree(n + 1, 0);
        
        // 2. Build edges correctly
        for (auto& sequence : sequences) {
            for (int i = 0; i + 1 < sequence.size(); i++) {
                graph[sequence[i]].push_back(sequence[i+1]);
                indegree[sequence[i+1]]++;
            }
        }

        // 3. Initialize queue with nodes with indegree 0
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int idx = 0;
        
        while (!q.empty()) {
            // 4. If more than 1 node has indegree 0, not unique
            if (q.size() > 1) return false;
            
            int curr = q.front();
            q.pop();
            
            // 5. Check order immediately
            if (curr != nums[idx]) {
                return false;
            }
            idx++;

            for (auto neighbor : graph[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // 6. Final check: all nodes should be used
        return idx == n;
    }
};
