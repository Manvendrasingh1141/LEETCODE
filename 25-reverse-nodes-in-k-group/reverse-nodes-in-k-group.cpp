class Solution {
public:
    ListNode* ReverseLL(ListNode* start, ListNode* end, ListNode* prev) {
        ListNode* temp = NULL;
        ListNode* stop = end->next;
        while (start != stop) {
            temp = start->next;
            start->next = prev;
            prev = start;
            start = temp;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        if (!head || k == 1)
            return head;

        ListNode *start = head, *end = head, *prev = NULL;

        while (end) {
            for (int i = 1; i < k; i++) {
                if (!end || !end->next)
                    return head;
                end = end->next;
            }

            ListNode* temp = end->next;
            ListNode* newHead = ReverseLL(start, end, temp);
            if (prev == NULL)
                head = newHead;
            else
                prev->next = newHead;
            prev = start;
            start = temp;
            end = temp;
        }

        return head;
    }
};