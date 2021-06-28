

/*
Structure of the node of the tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

bool travel(Node *root1,Node *root2){
   if((root1==NULL) && (root2==NULL))
        return true;
    if((root1==NULL) || (root2==NULL))
        return false;
    return (root1->data==root2->data) && travel(root1->left,root2->right) && travel(root1->right,root2->left);
}
bool isSymmetric(struct Node* root)
{
    if(root==NULL)
        return true;
	return travel(root->left,root->right);
}