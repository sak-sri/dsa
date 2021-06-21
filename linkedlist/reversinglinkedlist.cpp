class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode *left=NULL,*right=head->next;
        while(head){
            head->next=left;
            left=head;
            head=right;
            if(head)
                right=head->next;
            else 
                break;
        }
        return left;
    }
};