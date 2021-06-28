/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int,int> mp;
    TreeNode* construct(int l1,int h1,int l2,int h2,vector<int> &inorder,vector<int> &postorder){
        if(l2>h2)
            return NULL;
        if(l2==h2){
            return new TreeNode(postorder[l2]);
        }else{
            TreeNode *root=new TreeNode(postorder[h2]);
            int i=mp[root->val];
            int leftSubTree=0,rightSubTree=0;
            leftSubTree=i-l1;
            rightSubTree=h1-i;
            root->left=construct(l1,i-1,l2,l2+leftSubTree-1,inorder,postorder);
            root->right=construct(i+1,h1,l2+leftSubTree,h2-1,inorder,postorder);
            return root;
            
        }
    } 
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return construct(0,n-1,0,n-1,inorder,postorder);
    }
};