
class Solution {
public:
    ListNode *detectCycle(ListNode *start) {
        ListNode *current = start,*ans=NULL;
        unordered_map<ListNode*,bool>add;
        while(current){
            if(add[current]){
                return current;
            }
            add[current] = 1;
            current=current->next;
        }
        return ans;
    }
};