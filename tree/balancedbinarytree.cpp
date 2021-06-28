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
    bool isheightBalanced=true;
    int helper(TreeNode *root){
        if(root==NULL)
            return 0;
        int leftheight=helper(root->left);
        int rightheight=helper(root->right);
        if(abs(leftheight-rightheight)>1){
            isheightBalanced=false;
        }
        return 1+max(leftheight,rightheight);

    }
    bool isBalanced(TreeNode* root) {
        helper(root);
        return isheightBalanced;
    }
};