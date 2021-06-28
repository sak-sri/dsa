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
    TreeNode* construct(int l1,int h1,int l2,int h2,vector<int> &preorder,vector<int> &inorder,unordered_map<int,int> &mp){
       // cout<<l1<<" "<<h1<<" "<<l2<<" "<<h2<<endl;
        if(l1>h1)
            return NULL;
        if(l1==h1){
            return new TreeNode(preorder[l1]);
        }
        else{
            TreeNode *root=new TreeNode(preorder[l1]);
            int leftSubTreeSize=0,rightSubTreeSize=0;
            int i=mp[root->val];
            leftSubTreeSize=i-l2;
            rightSubTreeSize=h2-i;
            root->left=construct(l1+1,l1+leftSubTreeSize,l2,i-1,preorder,inorder,mp);
            root->right=construct(l1+leftSubTreeSize+1,l1+leftSubTreeSize+rightSubTreeSize,i+1,h2,preorder,inorder,mp);
            return root;
        }
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[preorder[i]]=-1;
        }
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return construct(0,n-1,0,n-1,preorder,inorder,mp);
    }
};