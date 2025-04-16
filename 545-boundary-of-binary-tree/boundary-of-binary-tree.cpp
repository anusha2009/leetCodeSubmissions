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
    bool isLeaf(TreeNode* t) {
        return t->left == nullptr && t->right == nullptr;
    }
    void addLeaves(vector<int>& res, TreeNode* root) {
        if(isLeaf(root)) {
            res.push_back(root->val);
        } else {
            if(root->left != nullptr) {
                addLeaves(res, root->left);
            }
            if(root->right != nullptr) {
                addLeaves(res, root->right);
            }
        }
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) {
            return res;
        }
        if(!isLeaf(root)) {
            res.push_back(root->val);
        }
        TreeNode* t = root->left;
        while(t != nullptr) {
            if(!isLeaf(t)) {
                res.push_back(t->val);
            }
            if(t->left != nullptr) {
                t = t->left;
            } else {
                t = t->right;
            }
        }
        addLeaves(res, root);
        stack<int> s;
        t = root->right;
        while(t != nullptr) {
            if(!isLeaf(t)) {
                s.push(t->val);
            }
            if(t->right != nullptr) {
                t = t->right;
            } else {
                t = t->left;
            }
        }
        while(!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
};