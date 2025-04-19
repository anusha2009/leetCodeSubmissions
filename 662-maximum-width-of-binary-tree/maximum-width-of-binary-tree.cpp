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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        queue<pair<TreeNode*, int>> q;
        int maxWidth = 0;
        q.push({root, 0});
        while(!q.empty()) {
            int currLevel = q.size();
            auto leftIndex = q.front().second;
            int rightIndex;
            for(int i = 0; i<currLevel; i++) {
                auto right = q.front();
                rightIndex = right.second;
                TreeNode* node = right.first;
                q.pop();
                if(node->left != nullptr) {
                    q.push({node->left, 2LL*right.second + 1});
                }
                if(node->right != nullptr) {
                    q.push({node->right, 2LL*right.second + 2});
                }
            }
            maxWidth = max(maxWidth, rightIndex - leftIndex + 1);
    
        }
        return maxWidth; 
    }
};