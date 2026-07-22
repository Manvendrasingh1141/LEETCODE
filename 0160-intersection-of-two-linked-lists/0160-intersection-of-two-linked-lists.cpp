/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL)return NULL;
        ListNode *start1=headA,*start2=headB;
        while(start1 !=start2){
            start1=start1->next;
            start2=start2->next;
            if(start1==start2)return start1;
            if(!start1)start1=headB;
            if(!start2)start2=headA;
        }
            return start1;
    }
};

