#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
class Solution
{
  public:
    //Function to convert binary tree into circular doubly linked list.
    void travel(Node *root,Node **head){
        if(root==NULL)
            return;
        static Node* prev=NULL;
        travel(root->left,head);
        if(prev==NULL){
            *head=root;
        }else{
            root->left=prev;
            prev->right=root;
        }
        prev=root;
        travel(root->right,head);
    }
    Node *bTreeToCList(Node *root)
    {
        Node *head=NULL;
        travel(root,&head);
        Node *temp=head;
        while(temp){
            if(temp->right==NULL){
                temp->right=head;
                head->left=temp;
                break;
            }
            temp=temp->right;
        }
        return head;
    }
};