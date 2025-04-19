class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> output;
        if (!root) return output;

        unordered_map<int, vector<pair<int, int>>> columnTable;
        queue<tuple<TreeNode*, int, int>> q; // node, column, row
        q.push({root, 0, 0});
        int minCol = 0, maxCol = 0;

        while (!q.empty()) {
            auto [node, col, row] = q.front();
            q.pop();

            columnTable[col].emplace_back(row, node->val);
            minCol = min(minCol, col);
            maxCol = max(maxCol, col);

            if (node->left) q.push({node->left, col - 1, row + 1});
            if (node->right) q.push({node->right, col + 1, row + 1});
        }

        for (int col = minCol; col <= maxCol; ++col) {
            auto& vec = columnTable[col];
            sort(vec.begin(), vec.end()); // Sort by row, then value
            vector<int> sortedCol;
            for (auto& [r, val] : vec) {
                sortedCol.push_back(val);
            }
            output.push_back(sortedCol);
        }

        return output;
    }
};
