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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *current=head,*temp=NULL;
        if(current->next==NULL)return NULL;
        int c=0;
        while(current){
            c++;
            current=current->next;
        }
        current = head;
        if(n==c){
            temp = current;
            current = current->next;
            delete temp;
            return current;
        }

        for(int i=0;i<c-n;i++){
            temp = current;
            current = current->next;
        }
            temp->next = current->next;
            delete current;
    	return head;
    }
};