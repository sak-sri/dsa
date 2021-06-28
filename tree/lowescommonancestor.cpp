class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node *ans=NULL;
    int findNodes(Node *root,int n1,int n2){
        if(root==NULL)
            return INT_MAX;
        if(root->data==n1 || root->data==n2){
            int x=findNodes(root->left,n1,n2);
            int y=findNodes(root->right,n1,n2);
            if((root->data==n1) && (x==n2 || y==n2) && !ans){
                ans=root;
            }
            else if((root->data==n2) && (x==n1 || y==n1) && !ans){
                ans=root;
            }
            return root->data;
        }
        int x=findNodes(root->left,n1,n2);
        int y=findNodes(root->right,n1,n2);
        if(x!=INT_MAX && y!=INT_MAX && !ans){
            ans=root;
        }
        if(x!=INT_MAX)
            return x;
        if(y!=INT_MAX)
            return y;
        return INT_MAX;
        
    }
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       findNodes(root,n1,n2);
       return ans;
    }
};