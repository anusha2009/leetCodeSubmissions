/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        vector<vector<int>> adjList(n);
        set<int> candidates;
        set<int> invalidCandidates;
        int result = -1;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(i!=j && knows(i, j)) {
                    adjList[i].push_back(j);
                }
            }
        }
        for(int i = 0; i<adjList.size(); i++) {
            if(adjList[i].empty()) {
                cout<<i<<'\n';
                candidates.insert(i);
            }
        }

        for(int node : candidates) {
            for(int i = 0; i<adjList.size(); i++) {
                if(i != node && find(adjList[i].begin(), adjList[i].end(), node) == adjList[i].end()) {
                    invalidCandidates.insert(node);
                }
            }
        }
        for(int node : candidates) {
            if(find(invalidCandidates.begin(), invalidCandidates.end(), node) == invalidCandidates.end()) {
                result = node;
            }
        }
        return result;
    }
};