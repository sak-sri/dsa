void construct(Node* root,int key){
    if(root==NULL || (root->data==key))
        return;
    if((root->left==NULL) && (root->right==NULL)){
        if(root->data>key)
            root->left=new Node(key);
        else if(root->data<key)
            root->right=new Node(key);
    }else if(root->data<key){
        if(!root->right){
            root->right=new Node(key);
            return;
        }
        construct(root->right,key);
    }else{
        if(!root->left){
            root->left=new Node(key);
            return;
        }
        construct(root->left,key);
    }
}
Node* insert(Node* root, int key)
{
    if(root==NULL){
        root=new Node(key);
        return root;
    }else{
        construct(root,key);
        return root;
    }
}
