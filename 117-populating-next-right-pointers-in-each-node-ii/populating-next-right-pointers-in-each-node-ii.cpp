class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }
        // Initialize a queue data structure which contains
        // just the root of the tree
        std::queue<Node*> Q;
        Q.push(root);
        // Outer while loop which iterates over
        // each level
        while (!Q.empty()) {
            // Note the size of the queue
            int size = Q.size();
            // Iterate over all the nodes on the current level
            for (int i = 0; i < size; i++) {
                // Pop a node from the front of the queue
                Node* node = Q.front();
                Q.pop();
                // This check is important. We don't want to
                // establish any wrong connections. The queue will
                // contain nodes from 2 levels at most at any
                // point in time. This check ensures we only
                // don't establish next pointers beyond the end
                // of a level
                if (i < size - 1) {
                    node->next = Q.front();
                }
                // Add the children, if any, to the back of
                // the queue
                if (node->left != nullptr) {
                    Q.push(node->left);
                }
                if (node->right != nullptr) {
                    Q.push(node->right);
                }
            }
        }
        // Since the tree has now been modified, return the root node
        return root;
    }
};