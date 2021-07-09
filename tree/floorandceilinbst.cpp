#include<bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    Node *left, *right;
};
Node* newNode(int key)
{
    Node* node = new Node;
    node->data = key;
    node->left = node->right = nullptr;
 
    return node;
}
Node* insert(Node* root, int key)
{
    if (root == nullptr) {
        return newNode(key);
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    }
    else {
        root->right = insert(root->right, key);
    }
 
    return root;
}

void findFloorCeil(Node* root, Node* &floor, Node* &ceil, int key)
{
    if (root == nullptr) {
        return;
    }
 
    
    if (root->data == key)
    {
        floor = root;
        ceil = root;
    }
 
    
    else if (key < root->data)
    {
        ceil = root;
        findFloorCeil(root->left, floor, ceil, key);
    }
    else {
        floor = root;
        findFloorCeil(root->right, floor, ceil, key);
    }
}
 
