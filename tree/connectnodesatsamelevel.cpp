

class Solution
{
    public:
    //Function to connect nodes at same level.
    pair<Node*,Node*> getNextRight(Node *parent,Node *child){
        while(parent){
            if(parent->left==child){
                if(parent->right)
                    return {parent,parent->right};
                else{
                    parent=parent->nextRight;
                }
            }else if(parent->right==child){
                parent=parent->nextRight;
            }else{
                if(parent->left){
                    return {parent,parent->left};
                }else if(parent->right){
                    return {parent,parent->right};
                }else{
                    parent=parent->nextRight;
                }
            }
        }
        return {NULL,NULL};
    }
    void connect(Node *root)
    {
       if(root==NULL)
            return;
       Node *p=root,*q=NULL;
       p->nextRight=NULL;
       while(p){
          if(p->left){
              if(!q)
                q=p->left;
              if(p->right){
                  p->left->nextRight=p->right;
                  pair<Node*,Node*> next=getNextRight(p,p->right);
                  p->right->nextRight=next.second;
                  p=next.first;
              }else{
                    pair<Node*,Node*> next=getNextRight(p,p->left);
                    p->left->nextRight=next.second;
                    p=next.first;
              }
          }
          else if(p->right){
              if(!q)
                q=p->right;
              pair<Node*,Node*> next=getNextRight(p,p->right);
              p->right->nextRight=next.second;
              p=next.first;
             
          }else{
                p=p->nextRight;
          }
          if(!p){
              p=q;
              q=NULL;
          }
       }
    }    
      
};


