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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *curr1,*curr2,*prev1,*prev2,*head;
        if(l1==NULL)
            return l2;
        else if(l2==NULL)
            return l1;
        curr1=l1;
        prev1=l1;
        curr2=l2;
        prev2=l2;
        head=NULL;
        while(curr1 && curr2){
            if(curr1->val<curr2->val){
                if(head==NULL)
                    head=curr1;
                while(curr1 && curr1->val<curr2->val){
                    prev1=curr1;
                    curr1=curr1->next;
                }
                prev1->next=curr2;
            }else{
                 if(head==NULL)
                     head=curr2;
                 while(curr2 && curr2->val<=curr1->val){
                    prev2=curr2;
                    curr2=curr2->next;
                }
                prev2->next=curr1;
            }
        }
        return head;
    }
};