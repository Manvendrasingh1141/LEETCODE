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
    ListNode* reverseLL(ListNode *start){
        ListNode *current = start,*prev = NULL,*temp;
        while(current){
            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode*slow=head,*fast=head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* ptr=head;
        ListNode* current=reverseLL(slow->next);
        while(current){
            if(ptr->val!=current->val)return 0;
            current = current->next;
            ptr = ptr->next;
        }


        return 1;
    }
};
 