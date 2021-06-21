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
  if(root==NULL)
    return NULL;
  Node *head=root,*headnex=root->next;
  Node *temp1=head,*temp2=headnex;
  while(temp2){
      Node *temp=new Node(-1);
      while(temp1 && temp2){
          if(temp1->data<=temp2->data){
              temp->bottom=temp1;
              temp1=temp1->bottom;
              temp=temp->bottom;
          }else{
              temp->bottom=temp2;
              temp2=temp2->bottom;
              temp=temp->bottom;
          }
      }
      while(temp1){
          temp->bottom=temp1;
          temp1=temp1->bottom;
          temp=temp->bottom;
      }
      while(temp2){
          temp->bottom=temp2;
          temp2=temp2->bottom;
          temp=temp->bottom;
      }
      if(head->data>headnex->data){
          head=headnex;
      }
      temp1=head;
      headnex=headnex->next;
      temp2=headnex;
  }
  return head;
  
}

