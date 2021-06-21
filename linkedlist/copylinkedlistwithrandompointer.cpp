/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        Node *curr=head,*prev=head,*clonedHead=NULL;
        while(curr){
            Node *temp=new Node(curr->val);
            if(!clonedHead)
                clonedHead=temp;
            curr=curr->next;
            prev->next=temp;
            temp->next=curr;
            prev=curr;
        }
        curr=head;
        Node *clonedcurr=clonedHead;
        while(clonedcurr->next){
            if(curr->random){
                clonedcurr->random=curr->random->next;
            }
                clonedcurr=clonedcurr->next->next;
                curr=curr->next->next;
        }
        if(curr->random)
            clonedcurr->random=curr->random->next;
        curr=head;
        clonedcurr=clonedHead;
        if(clonedcurr->next){
            Node *nex=curr->next->next;
            Node *clonednex=clonedcurr->next->next;
            while(clonednex->next){
                clonedcurr->next=clonednex;
                curr->next=nex;
                clonedcurr=clonedcurr->next;
                curr=curr->next;
                clonednex=clonednex->next->next;
                nex=nex->next->next;
            }
            clonedcurr->next=clonednex;
            curr->next=nex;
            nex->next=NULL;
        }else{
            curr->next=NULL;
        }
        return clonedHead;
    }
};