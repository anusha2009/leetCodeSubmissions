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
    ListNode* partition(ListNode* head, int x) {
        ListNode* first = new ListNode(0);
        ListNode* second = new ListNode(0);
        ListNode* third = new ListNode(0);
        ListNode* ptr1 = second;
        ListNode* ptr2 = third;
        first->next = head;
        ptr1 = second;
        ptr2 = third;
        while(head != NULL) {
            if(head->val < x) {
                second->next = head;
                second = second->next;
                
            } else {
                third->next = head;
                third = third->next;
            }
            head = head->next;
            
        }
        third->next = NULL;
        second->next = ptr2->next;
        return ptr1->next;



    }
};