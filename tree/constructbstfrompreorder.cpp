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
    TreeNode* construct(int l,int h,vector<int> &preorder){
        if(l>h)
            return NULL;
        if(l==h)
            return new TreeNode(preorder[l]);
        TreeNode* root=new TreeNode(preorder[l]);
        int ub=upper_bound(preorder.begin()+l,preorder.begin()+h+1,preorder[l])-preorder.begin();
        root->left=construct(l+1,ub-1,preorder);
        root->right=construct(ub,h,preorder);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return construct(0,preorder.size()-1,preorder);
    }
};