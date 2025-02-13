class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> queue;
        unordered_set<string> seen;
        queue.push(start);
        seen.insert(start);

        int steps = 0;

        while(!queue.empty()) {
            int nodes = queue.size();
            for(int j=0;j<nodes;j++) {
                string node = queue.front();
                queue.pop();
                if(node == end) {
                    return steps;
                }
                for(char c:"ACGT") {
                    for(int i=0;i<node.size();i++) {
                        string neighbour = node;
                        neighbour[i] = c;
                        if(!seen.count(neighbour) && find(bank.begin(), bank.end(), neighbour) != bank.end()) {
                            queue.push(neighbour);
                            seen.insert(neighbour);
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};