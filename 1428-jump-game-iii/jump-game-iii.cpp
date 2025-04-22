class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<pair<int, int>> q;
        vector<bool> seen(arr.size(), 0);
        q.push({start, arr[start]});
        seen[start] = 1;
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            int node = curr.first;
            int val = curr.second;
            if(val == 0) {
                return true;
            }
            if(node + val < arr.size() && !seen[node+val]) {
                seen[node+val] = 1;
                q.push({node+val, arr[node+val]});
            }
            if(node - val >= 0 && !seen[node-val]) {
                seen[node-val] = 1;
                q.push({node-val, arr[node-val]});
            }
        }
        return false;

    }
};