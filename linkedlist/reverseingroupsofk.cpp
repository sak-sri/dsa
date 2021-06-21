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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)
            return head;
        ListNode *left,*right,*root;
        root=head;
        left=NULL;
        right=head->next;
        int temp=0;
        while(head){
            temp++;
            head=head->next;
        }
        if(temp<k)
            return root;
        head=root;
        temp=0;
        while(head && temp<k){
            head->next=left;
            left=head;
            head=right;
            if(right==NULL)
                break;
            right=right->next;
            temp++;
        }
        root->next=reverseKGroup(head,k);
        return left;
        
    }
};