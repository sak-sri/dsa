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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode *h1=l1,*h2=l2;
        while(l1->next && l2->next){
            int temp=l1->val+l2->val+carry;
            l1->val=temp%10;
            carry=temp/10;
            l1=l1->next;
            l2=l2->next;
        }
        if(l1->next){
            int temp=l1->val+l2->val+carry;
            l1->val=temp%10;
            carry=temp/10;
            l1=l1->next;
            while(l1->next){
                int temp=l1->val+carry;
                l1->val=temp%10;
                carry=temp/10;
                l1=l1->next;
            }
            if(carry){
                int temp=l1->val+carry;
                l1->val=temp%10;
                carry=temp/10;
                if(carry)
                    l1->next=new ListNode(carry);
            }
            return h1;
        }else if(l2->next){
            l1->next=l2->next;
            int temp=l1->val+l2->val+carry;
            l1->val=temp%10;
            carry=temp/10;
            l1=l1->next;
            while(l1->next){
                int temp=l1->val+carry;
                l1->val=temp%10;
                carry=temp/10;
                l1=l1->next;
            }
            if(carry){
                int temp=l1->val+carry;
                l1->val=temp%10;
                carry=temp/10;
                if(carry)
                    l1->next=new ListNode(carry);
            }
            return h1;
        }else{
            int temp=l1->val+l2->val+carry;
            l1->val=temp%10;
            carry=temp/10;
            if(carry)
                l1->next=new ListNode(carry);
            return h1;
        }
    }
};