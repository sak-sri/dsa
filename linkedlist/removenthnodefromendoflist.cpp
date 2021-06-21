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
        ListNode *first=head,*second=head;
        for(int i=0;i<n+1;i++){
            if(first==NULL){
             if(i==n-1){
                 head->next=NULL;
                 return head;
             }else if(i==n){
                 head=head->next;
                 return head;
             }
            }
            first=first->next;
        }
        while(first){
            second=second->next;
            first=first->next;
        }
        second->next=second->next->next;
        return head;
    }
};