pair<pair<long int,long int>,pair<bool,long int> > inorder(Node* root){
    if(root==NULL){
        return {{LONG_MIN,LONG_MAX},{true,0}};
    }else{
        pair<pair<long int,long int>,pair<bool,long int> > left=inorder(root->left);
        pair<pair<long int,long int>,pair<bool,long int> > right=inorder(root->right);
        bool isBst=left.second.first && right.second.first && 
        (left.first.first<root->data) && (right.first.second>root->data);
        if(isBst){
            return {{max((long)root->data,max(left.first.first,right.first.first)),min(min(right.first.second,left.first.second),(long)root->data)},{true,1ll+left.second.second+right.second.second}};
        }else{
            return {{max((long)root->data,left.first.first),min(right.first.second,(long)root->data)},{false,max(left.second.second,right.second.second)}};
        }
    }
}
int largestBst(Node *root)
{
    return inorder(root).second.second;
}