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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
            return NULL;
        ListNode *fast=head,*slow=head;
        fast=fast->next;
        if(fast==NULL)
            return NULL;
        fast=fast->next;
        if(fast==NULL)
            return NULL;
        slow=slow->next;
        while(fast!=slow){
            slow=slow->next;
            if(slow==NULL || fast==NULL)
                return NULL;
            if(fast->next)
                fast=fast->next->next;
            else 
                return NULL;
        }
        while(slow!=head){
            head=head->next;
            slow=slow->next;
        }
        return head;
    }
};