class Solution {
public:
    void remove(ListNode* &head, ListNode* prev, ListNode* curr, int val) {
        if (!curr) return;

        if (curr->val == val && prev == NULL) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            remove(head, NULL, head, val);
            return;
        }

        if (curr->val == val) {
            ListNode* temp = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete temp;
            remove(head, prev, curr, val);
            return;
        }
        remove(head, curr, curr->next, val);
    }

    ListNode* removeElements(ListNode* head, int val) {
        remove(head, NULL, head, val);
        return head;
    }
};