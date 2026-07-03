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
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;

        while(fast!=nullptr && fast->next!= nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = head;
        
        ListNode *prev = nullptr;
        ListNode *curr = slow;
        ListNode *forw = slow;

        while(curr!=nullptr){
            forw = curr->next;
            curr->next =prev;
            prev = curr;
            curr = forw;
        }
       
        while(prev !=  nullptr){
            if(prev->val != fast->val){
                return false;
            }
            prev = prev->next;
            fast = fast->next;
        }



        return true;
    }
};