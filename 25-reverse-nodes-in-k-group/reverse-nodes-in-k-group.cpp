class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head, int k) {
        ListNode* new_head = nullptr;
        ListNode* ptr = head;
        while (k > 0) {
            ListNode* next_node = ptr->next;
            ptr->next = new_head;
            new_head = ptr;
            ptr = next_node;
            k--;
        }
        return new_head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ptr = head;
        ListNode* ktail = nullptr;
        ListNode* new_head = nullptr;
        while (ptr != nullptr) {
            int count = 0;
            ptr = head;
            while (count < k && ptr != nullptr) {
                ptr = ptr->next;
                count++;
            }
            if (count == k) {
                ListNode* revHead = this->reverseLinkedList(head, k);
                if (new_head == nullptr) new_head = revHead;
                if (ktail != nullptr) ktail->next = revHead;
                ktail = head;
                head = ptr;
            }
        }
        if (ktail != nullptr) ktail->next = head;
        return new_head == nullptr ? head : new_head;
    }
};