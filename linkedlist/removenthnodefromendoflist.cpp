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
        ListNode *forward=head,*backward=head;
        for(int i=0;i<n;i++){
            forward=forward->next;
        }
        if(forward==NULL){
           head=head->next;
           return head;
        }else{
            while(forward->next){
                forward=forward->next;
                backward=backward->next;
            }
            backward->next=backward->next->next;
            return head;
        }
    }
};