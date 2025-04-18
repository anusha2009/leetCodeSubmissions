/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr) {
            return {};
        }
        vector<vector<int>> result;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            vector<int> level;
            for(int i=0;i<n;i++) {
                Node* node = q.front();
                q.pop();
                level.push_back(node->val);
                for(auto n : node->children) q.push(n); 
            }
            result.push_back(level);
        }
        return result;

        
    }
};