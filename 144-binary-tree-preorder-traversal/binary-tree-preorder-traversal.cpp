class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> output;
        TreeNode* node = root;
        while (node != nullptr) {
            if (node->left == nullptr) {
                output.push_back(node->val);
                node = node->right;
            } else {
                TreeNode* predecessor = node->left;
                while (predecessor->right != nullptr &&
                       predecessor->right != node) {
                    predecessor = predecessor->right;
                }
                if (predecessor->right == nullptr) {
                    output.push_back(node->val);
                    predecessor->right = node;
                    node = node->left;
                } else {
                    predecessor->right = nullptr;
                    node = node->right;
                }
            }
        }
        return output;
    }
};