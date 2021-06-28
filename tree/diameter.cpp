class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int dia=0;
    int finddia(Node *root){
        if(root==NULL)
            return 0;
        int left=1+finddia(root->left);
        int right=1+finddia(root->right);
        int throughroot=left+right-1;
        int temp=max(left,right);
        dia=max(max(temp,throughroot),dia);
        return temp;
    }
    int diameter(Node* root) {
        
        finddia(root);
        return dia;
    }
};