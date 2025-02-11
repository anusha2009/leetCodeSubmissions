class Solution {
public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        gainFromSubtree(root);
        return maxSum;
    }

private:
    int maxSum;
    // post order traversal of subtree rooted at `root`
    int gainFromSubtree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        // add the path sum from left subtree. Note that if the path
        // sum is negative, we can ignore it, or count it as 0.
        // This is the reason we use `max` here.
        int gainFromLeft = max(gainFromSubtree(root->left), 0);
        // add the path sum from right subtree. 0 if negative
        int gainFromRight = max(gainFromSubtree(root->right), 0);
        // if left or right path sum are negative, they are counted
        // as 0, so this statement takes care of all four scenarios
        maxSum = max(maxSum, gainFromLeft + gainFromRight + root->val);
        // return the max sum for a path starting at the root of subtree
        return max(gainFromLeft + root->val, gainFromRight + root->val);
    }
};