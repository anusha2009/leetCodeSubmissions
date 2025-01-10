/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* first = new ListNode(0);
        first->next = head;
        ListNode* second = first;

        while(first->next != NULL && first->next->next != NULL) {
            if(first->next->next->val == first->next->val) {
                int val = first->next->val;
                while(first->next && first->next->val == val) {
                    first->next = first->next->next;
                }
            } else {
                first = first->next;
            }
            
        }
        return second->next;
        
    }
};