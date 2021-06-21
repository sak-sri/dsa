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
        int l1=0,l2=0;
        ListNode *temp1=headA,*temp2=headB;
        while(temp1){
            temp1=temp1->next;
            l1++;
        }
        while(temp2){
            temp2=temp2->next;
            l2++;
        }
        int diff=abs(l2-l1);
        if(l2>l1){
            while(diff--){
                headB=headB->next;
            }
            if(headA==headB)
                return headA;
            while(headA && headB && headB->next!=headA->next){
                headB=headB->next;
                headA=headA->next;
            }
            if(headB->next==NULL)
                return NULL;
            return headB->next;
        }else{
            while(diff--){
                headA=headA->next;
            }
            if(headA==headB)
                return headA;
            while(headA && headA && headB->next!=headA->next){
                headB=headB->next;
                headA=headA->next;
            }
            if(headB->next==NULL)
                return NULL;
            return headB->next;
        }
    }
};