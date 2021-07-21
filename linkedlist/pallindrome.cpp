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
        int len=0;
        ListNode* temp=head;
        while(temp){
            len++;
            temp=temp->next;
        }
        if(len==1){
            return true;
        }
        temp=head;
        ListNode *prev=temp,*nex=temp,*back=NULL;
        for(int i=0;i<(len/2)+(len%2);i++){
            prev=temp;
            temp=temp->next;
        }
        while(temp){
            nex=temp->next;
            temp->next=back;
            back=temp;
            temp=nex;
        }
        prev->next=back;
        ListNode *head1=head,*head2=back;
        for(int i=0;i<(len/2);i++){
            if(head1->val!=head2->val){
                return false;
            }
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }
};