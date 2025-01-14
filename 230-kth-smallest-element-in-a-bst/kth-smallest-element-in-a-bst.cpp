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
    void inorderT(TreeNode* root,vector<int>& inorder){
        if(!root) return ;
        inorderT(root->left,inorder);
        inorder.push_back(root->val);
        inorderT(root->right,inorder);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;
        inorderT(root,inorder);
        if(k>inorder.size()) return -1;
        return inorder[k-1];
    }
};