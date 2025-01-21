class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }
        // Start with the root node. There are no next pointers
        // that need to be set up on the first level
        Node* leftmost = root;
        // Once we reach the final level, we are done
        while (leftmost->left != nullptr) {
            // Iterate the "linked list" starting from the head
            // node and using the next pointers, establish the
            // corresponding links for the next level
            Node* head = leftmost;
            while (head != nullptr) {
                // CONNECTION 1
                head->left->next = head->right;
                // CONNECTION 2
                if (head->next != nullptr) {
                    head->right->next = head->next->left;
                }
                // Progress along the list (nodes on the current level)
                head = head->next;
            }
            // Move onto the next level
            leftmost = leftmost->left;
        }
        return root;
    }
};