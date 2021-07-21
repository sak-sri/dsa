

/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   Node *head1=NULL,*head2=NULL;
   head1=root;
   if(head1)
        head2=head1->next;
   while(head2){
       Node *temp1=head1,*temp2=head2;
       while(head1 && head2){
           Node *prev1=head1,*prev2=head2;
           bool val1=false;
           while(head1 && head2 && (head1->data<=head2->data)){
               prev1=head1;
               head1=head1->bottom;
               val1=true;
           }
           if(val1)
                prev1->bottom=head2;
           bool val2=false;
           while(head2 && head1 && (head1->data>=head2->data)){
               prev2=head2;
               head2=head2->bottom;
               val2=true;
           }
           if(val2)
                prev2->bottom=head1;
       }
       if(temp1->data<=temp2->data){
           head1=temp1;
       }else{
           head1=temp2;
       }
       if(temp2)
            head2=temp2->next;
       temp1->next=NULL;
       temp2->next=NULL;
   }
   return head1;
}

