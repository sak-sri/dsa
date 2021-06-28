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
    int maxPathSumValue=INT_MIN;
    int helper(TreeNode *root){
        if(root==NULL)
            return 0;
        int maxPathSumLeft=root->val+helper(root->left);
        int maxPathSumRight=root->val+helper(root->right);
        int pathSumThroughNode=maxPathSumLeft+maxPathSumRight-(root->val);
        maxPathSumValue=max(max(maxPathSumLeft,maxPathSumRight),max(pathSumThroughNode,maxPathSumValue));
        maxPathSumValue=max(root->val,maxPathSumValue);
        return max(maxPathSumLeft,max(maxPathSumRight,root->val));
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxPathSumValue;
    }
};