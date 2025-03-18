class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* l, ListNode* r) { return l->val > r->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
        for (auto l : lists) {
            if (l) q.push(l);
        }
        ListNode head(0);
        ListNode* point = &head;
        while (!q.empty()) {
            point->next = q.top();
            q.pop();
            point = point->next;
            if (point->next) q.push(point->next);
        }
        return head.next;
    }
};