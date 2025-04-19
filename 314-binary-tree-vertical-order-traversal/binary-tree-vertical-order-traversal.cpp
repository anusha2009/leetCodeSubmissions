/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> output;
        if(root == nullptr) {
            return output;
        }
        unordered_map<int, vector<int>> columnTable;
        queue<pair<TreeNode*, int>> q;
        int column = 0;
        q.push({root, column});
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            root = p.first;
            column = p.second;
            if(root != nullptr) {
                columnTable[column].push_back(root->val);
                q.push({root->left, column-1});
                q.push({root->right, column+1});
            }
        }
        vector<int> keys;
        for(auto p : columnTable) {
            keys.push_back(p.first);
        }
        sort(keys.begin(), keys.end());
        for(int k : keys) {
            output.push_back(columnTable[k]);
        }
        return output;
    }
};