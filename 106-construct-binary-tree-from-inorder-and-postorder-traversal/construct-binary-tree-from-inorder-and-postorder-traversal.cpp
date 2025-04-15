class Solution {
    int post_idx;
    vector<int> postorder;
    vector<int> inorder;
    unordered_map<int, int> idx_map;

public:
    TreeNode* helper(int in_left, int in_right) {
        // if there are no elements to construct subtrees
        if (in_left > in_right) return NULL;
        // pick up post_idx element as a root
        int root_val = postorder[post_idx];
        TreeNode* root = new TreeNode(root_val);
        // root splits inorder list
        // into left and right subtrees
        int index = idx_map[root_val];
        // recursion
        post_idx--;
        // build the right subtree
        root->right = helper(index + 1, in_right);
        // build the left subtree
        root->left = helper(in_left, index - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->postorder = postorder;
        this->inorder = inorder;
        // start from the last postorder element
        post_idx = postorder.size() - 1;
        // build a hashmap value -> its index
        int idx = 0;
        for (int val : inorder) idx_map[val] = idx++;
        return helper(0, inorder.size() - 1);
    }
};