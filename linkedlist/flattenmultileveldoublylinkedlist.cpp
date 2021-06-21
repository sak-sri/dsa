/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL)
            return nullptr;
        Node *nex=head->next,*temp=head;
        while(nex){
            if(temp->child){
                temp->next=flatten(temp->child);
                temp->child=NULL;
                temp->next->prev=temp;
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=nex;
                nex->prev=temp;
            }
            nex=nex->next;
            temp=temp->next;
        }
        if(temp->child){
                temp->next=flatten(temp->child);
                temp->child=NULL;
                temp->next->prev=temp;
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=nex;
        }
        return head;
    }
};