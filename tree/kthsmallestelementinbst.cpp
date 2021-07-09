class Solution {
public:
    int ans;
    void inorder(TreeNode *root,int &k){
        if(!root)
            return;
        inorder(root->left,k);
        k--;
        if(k==0){
            ans=root->val;
        }
        inorder(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return ans;
    }
};