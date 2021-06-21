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
    bool hasCycle(ListNode *head) {
        ListNode *p1=head,*p2=head;
        if((head==NULL) || (head->next==NULL))
            return false;
        p1=p1->next;
        p2=p2->next->next;
        while(p1!=p2){
            p1=p1->next;
            if(!p1)
                return false;
            if(!p2->next)
                return false;
            p2=p2->next->next;
            if(!p2)
                return false;
        }
        return true;
        
    }
};