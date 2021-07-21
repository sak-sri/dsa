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
        Node *curr=head,*nex=head->next;
        while(curr){
            curr->next=new Node(curr->val);
            curr->next->next=nex;
            curr=nex;
            if(nex)
                nex=nex->next;
        }
        Node *head1=head,*head2=head->next,*next1=NULL,*next2=NULL;
        Node *ans=head2;
        if(head2)
            next1=head2->next;
        if(next1)
            next2=next1->next;
        while(head2->next){
            if(head1->random)
                head2->random=head1->random->next;
            head1=head2->next;
            head2=head1->next;
        }
        if(head1->random)
            head2->random=head1->random->next;
        head1=head;
        head2=head->next;
        while(head1){
            head1->next=next1;
            head1=next1;
            if(next2)
                next1=next2->next;
            head2->next=next2;
            head2=next2;
            if(next1)
                next2=next1->next;
        }
        if(head2){
            head2->next=NULL;
        }
        return ans;
    }
};