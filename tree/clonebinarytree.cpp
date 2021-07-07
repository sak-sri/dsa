#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node *random;
};
class Solution{
  public:
    Node* travel(Node *tree,unordered_map<Node*,Node*> &mp){
        if(tree==NULL)
            return NULL;
        Node *cloneNode;
        cloneNode->data=tree->data;
        cloneNode->random=NULL;
        mp[tree]=cloneNode;
        cloneNode->left=travel(tree->left,mp);
        cloneNode->right=travel(tree->right,mp);
        return cloneNode;
    }
    void copyRandom(Node *tree,Node *cloneNode,unordered_map<Node*,Node*> &mp){
        if(tree==NULL)
            return;
        cloneNode->random=mp[tree->random];
        copyRandom(tree->left,cloneNode->left,mp);
        copyRandom(tree->right,cloneNode->right,mp);
    }
    Node* cloneTree(Node* tree)
    {
        unordered_map<Node*,Node*> mp;
        mp[NULL]=NULL;
        Node* newtree=travel(tree,mp);
        copyRandom(tree,newtree,mp);
        return newtree;
    }
};