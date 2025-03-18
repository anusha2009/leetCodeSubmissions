class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right) {
            return NULL;
        }
        int p = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[p]);
        root->left = helper(nums, left, p - 1);
        root->right = helper(nums, p + 1, right);
        return root;
    }
};