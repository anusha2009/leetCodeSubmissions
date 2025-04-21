class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) {
            return n;
        }
        vector<int> indegree(n+1, 0);
        vector<int> outdegree(n+1, 0);
        for(auto t : trust) {
            indegree[t[1]]++;
            outdegree[t[0]]++;
        }
        for(int i = 0; i<indegree.size(); i++) {
            if(indegree[i] == n-1 && outdegree[i] == 0) {
                return i;
            } 
        }
        return -1;
    }
};