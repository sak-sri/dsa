/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        Node *prev=head,*curr=head;
        while(k--){
            prev=curr;
            curr=curr->next;
        }
        if(curr==NULL)
            return head;
        Node *newhead=curr;
        prev->next=NULL;
        while(curr->next){
            curr=curr->next;
        }
        curr->next=head;
        return newhead;
    }
};
    
