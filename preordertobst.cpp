#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left,*right;
    Node(int x){
        left=NULL;
        right=NULL;
        data=x;
    }   
};
Node* construct(int pre[],int &id,int lim,int sz){
    if((id==sz) || (pre[id]>lim)){
        return NULL;
    }
    Node* root=new Node(pre[id]);
    id++;
    root->left=construct(pre,id,root->data,sz);
    root->right=construct(pre,id,lim,sz);
    return root;
}
Node* constructTree(int pre[], int size)
{
    int id=0;
    return construct(pre,id,INT_MAX,size);
}
