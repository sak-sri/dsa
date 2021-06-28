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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1,q2;
        if(p==NULL && q==NULL)
            return true;
        if(p==NULL || q==NULL)
            return false;
        q1.push(p);
        q2.push(q);
        int cnt1=1,cnt2=1;
        int temp=0;
        while(!q1.empty() && !q2.empty()){
            temp=0;
            for(int i=0;i<cnt1;i++){
                TreeNode* parent1=q1.front();
                TreeNode* parent2=q2.front();
                q1.pop();
                q2.pop();
                if(parent1->val!=parent2->val){
                    return false;
                }
                if((parent1->right && !parent2->right) || (parent1->left && !parent2->left)){
                    return false;
                }
                if((!parent1->right) && (parent2->right) || (!parent1->left) && (parent2->left))
                    return false;
                if(parent1->right){
                    q1.push(parent1->right);
                    temp+=1;
                }
                if(parent1->left){
                    q1.push(parent1->left);
                    temp++;
                }
                if(parent2->right){
                    q2.push(parent2->right);
                }
                if(parent2->left)
                    q2.push(parent2->left);
            }
            cnt1=temp;
            cnt2=temp;
        }
        return true;
    }
};