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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr && subRoot == nullptr) {
            return true;
        }
        if (root == nullptr || subRoot == nullptr) {
            return false;
        }
        bool check = false;
        if(root->val == subRoot->val) {
            check = isSameTree(root, subRoot);
        }
        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);
        return left || right || check;
    }
    bool isSameTree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr && subRoot == nullptr) {
            return true;
        }
        if (root == nullptr || subRoot == nullptr) {
            return false;
        }
        if(root->val != subRoot->val) {
            return false;
        }
        bool left = isSameTree(root->left, subRoot->left);
        bool right = isSameTree(root->right, subRoot->right);
        return left && right;
    }
};