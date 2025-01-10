class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
            return head;
        int len = 0;
        ListNode* first = new ListNode(0);
        ListNode* second = new ListNode(0);
        ListNode* third = new ListNode(0);
        first->next = head;
        while(first->next != NULL) {
            len++;
            second = first;
            first = first->next;
        }
        k = k%len;
        len = len - k;
        first->next = head;
        
        while(len>0) {
            len--;
            first = first->next;
        }
        third->next = first->next;
        first->next = nullptr;
        return third->next;
    }
};