class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parents;
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root, nullptr);
        queue<TreeNode*> queue;
        unordered_set<TreeNode*> seen;
        queue.push(target);
        seen.insert(target);
        
        int distance = 0;
        while (!queue.empty() && distance < k) {
            int currentLength = queue.size();
            for (int i = 0; i < currentLength; i++) {
                TreeNode* node = queue.front();
                queue.pop();
                for (TreeNode* neighbor: {node->left, node->right, parents[node]}) {
                    if (neighbor != nullptr && seen.find(neighbor) == seen.end()) {
                        seen.insert(neighbor);
                        queue.push(neighbor);
                    }
                }
            }
            
            distance++;
        }
        
        vector<int> ans;
        while (!queue.empty()) {
            TreeNode* node = queue.front();
            queue.pop();
            ans.push_back(node->val);
        }

        return ans;
    }
    
    void dfs(TreeNode* node, TreeNode* parent) {
        if (node == nullptr) {
            return;
        }
        
        parents[node] = parent;
        dfs(node->left, node);
        dfs(node->right, node);
    }
};