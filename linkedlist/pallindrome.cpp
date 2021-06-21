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
        if(head->next==NULL)
            return true;
        int len=0;
        ListNode *temp=head;
        while(temp){
            temp=temp->next;
            len++;
        }
        ListNode *right=head,*left=head;
        for(int i=0;i<len/2;i++){
            left=right;
            right=right->next;
        }
        left->next=NULL;
        if(len%2)
            right=right->next;
        ListNode *back=NULL,*nex=right;
        while(right){
            nex=right->next;
            right->next=back;
            back=right;
            right=nex;
        }
        while(back && head){
            if(back->val!=head->val)
                return false;
            back=back->next;
            head=head->next;
        }
        return true;
    }
};